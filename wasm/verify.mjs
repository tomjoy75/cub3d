// Proves the bench measures real work: the buffer must be non-trivial, and
// walking must change it. A no-op renderer would post the same fast number.
import Cub3d from './cub3d.js';
const M = await Cub3d();
if (M.cwrap('cw_init','number',['string'])(process.argv[2] ?? 'maps/metal.cub') !== 0) process.exit(1);
const w = M.ccall('cw_width','number',[],[]), h = M.ccall('cw_height','number',[],[]);
const snap = () => {
  const p = M.ccall('cw_buffer','number',[],[]);
  return Uint8Array.from(M.HEAPU8.subarray(p, p + w*h*4));
};
M.ccall('cw_frame', null, [], []);
const a = snap();
const distinct = new Set();
for (let i = 0; i < a.length; i += 4) distinct.add(a[i] | a[i+1]<<8 | a[i+2]<<16);
M.ccall('cw_key', null, ['number'], [0x0077]); // W
M.ccall('cw_frame', null, [], []);
const b = snap();
let changed = 0;
for (let i = 0; i < a.length; i += 4) if (a[i] !== b[i] || a[i+1] !== b[i+1] || a[i+2] !== b[i+2]) changed++;
const nonzero = a.reduce((n,v) => n + (v !== 0 ? 1 : 0), 0);
console.log(JSON.stringify({
  pixels: w*h, nonzero_bytes: nonzero, distinct_colours: distinct.size,
  pixels_changed_after_step: changed,
  verdict: distinct.size > 50 && changed > w*h*0.05 ? 'RENDERING' : 'SUSPECT'
}));
