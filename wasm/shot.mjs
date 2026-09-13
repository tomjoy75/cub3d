// Renders one frame per map to a PNG, so map choice is made by looking rather
// than by reading ASCII. Spike tooling.
import Cub3d from './real.js';
import { writeFileSync } from 'node:fs';
import { deflateSync } from 'node:zlib';

const crcT = [...Array(256)].map((_, n) => { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xEDB88320 ^ (c >>> 1) : c >>> 1; return c >>> 0; });
const crc = b => { let c = 0xFFFFFFFF; for (const x of b) c = crcT[(c ^ x) & 255] ^ (c >>> 8); return (c ^ 0xFFFFFFFF) >>> 0; };
const chunk = (tag, data) => { const t = Buffer.from(tag), len = Buffer.alloc(4); len.writeUInt32BE(data.length);
  const c = Buffer.concat([t, data]), k = Buffer.alloc(4); k.writeUInt32BE(crc(c)); return Buffer.concat([len, c, k]); };

const [, , mapName, steps = '0', turns = '0'] = process.argv;
const M = await Cub3d();
if (M.cwrap('cw_init', 'number', ['string'])(`maps/${mapName}.cub`) !== 0) process.exit(1);
for (let i = 0; i < +turns; i++) M.ccall('cw_key', null, ['number'], [0xff53]);
for (let i = 0; i < +steps; i++) M.ccall('cw_key', null, ['number'], [0x0077]);
M.ccall('cw_frame', null, [], []);

const w = M.ccall('cw_width', 'number', [], []), h = M.ccall('cw_height', 'number', [], []);
const p = M.ccall('cw_buffer', 'number', [], []);
const src = M.HEAPU8.subarray(p, p + w * h * 4);
const raw = Buffer.alloc(h * (1 + w * 3));
for (let y = 0, o = 0; y < h; y++) { raw[o++] = 0;
  for (let x = 0; x < w; x++) { const i = (y * w + x) * 4;   // stored R,G,B,X
    raw[o++] = src[i]; raw[o++] = src[i + 1]; raw[o++] = src[i + 2]; } }
const ihdr = Buffer.alloc(13); ihdr.writeUInt32BE(w, 0); ihdr.writeUInt32BE(h, 4); ihdr[8] = 8; ihdr[9] = 2;
writeFileSync(`/tmp/shots/${mapName}.png`, Buffer.concat([
  Buffer.from([137,80,78,71,13,10,26,10]), chunk('IHDR', ihdr),
  chunk('IDAT', deflateSync(raw, { level: 9 })), chunk('IEND', Buffer.alloc(0))]));
console.log(`${mapName}.png ${w}x${h}`);
