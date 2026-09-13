// Boots the cub3D WebAssembly build and drives it from the browser.
//
// The engine expects a filesystem: cb_map_file.c opens the .cub with open(2),
// and cb_image_load asks the MiniLibX shim for each texture by path. So rather
// than change either, this fetches both and writes them into emscripten's
// virtual filesystem before cw_init. Textures arrive as PNG and are decoded by
// createImageBitmap - the browser's own decoder, which is why the build ships
// 402 KB of textures instead of 2.3 MB of raw buffers.

import Cub3d from './cub3d.js';

const KEY = {                       // real X11 keysyms; the C matches on these
  KeyW: 0x0077, KeyA: 0x0061, KeyS: 0x0073, KeyD: 0x0064,
  ArrowLeft: 0xff51, ArrowRight: 0xff53,
  KeyM: 0x006d, Space: 0x0020,
};
const HELD = new Set(['KeyW', 'KeyA', 'KeyS', 'KeyD', 'ArrowLeft', 'ArrowRight']);
const TAP = new Set(['KeyM', 'Space']);

const $ = (s) => document.querySelector(s);
const canvas = $('#view');
const ctx = canvas.getContext('2d', { alpha: false });

let M, image, W, H, ready = false, pending = false;
const held = new Set();
let currentMap = new URLSearchParams(location.search).get('map') || 'bonus_futur_du_retour_de_l_anterieur';

async function writeTexture(name) {
  const res = await fetch(`tex/${name}.png`);
  if (!res.ok) return;
  const bmp = await createImageBitmap(await res.blob());
  const off = new OffscreenCanvas(bmp.width, bmp.height);
  const o = off.getContext('2d', { willReadFrequently: true });
  o.drawImage(bmp, 0, 0);
  const px = o.getImageData(0, 0, bmp.width, bmp.height).data;
  // rgba/<name>.rgba: int32 w, int32 h, then R,G,B,X - the order the renderer
  // writes, so the framebuffer goes straight into ImageData with no swap.
  const out = new Uint8Array(8 + px.length);
  new DataView(out.buffer).setInt32(0, bmp.width, true);
  new DataView(out.buffer).setInt32(4, bmp.height, true);
  for (let i = 0; i < px.length; i += 4) {
    out[8 + i] = px[i]; out[9 + i] = px[i + 1]; out[10 + i] = px[i + 2]; out[11 + i] = 0;
  }
  M.FS.writeFile(`rgba/${name}.rgba`, out);
}

async function loadMap(name) {
  const src = await (await fetch(`maps/${name}.cub`)).text();
  M.FS.writeFile(`maps/${name}.cub`, src);
  const walls = [...src.matchAll(/^(?:NO|SO|WE|EA)\s+\S*?([\w]+)\.xpm/gm)].map((m) => m[1]);
  await Promise.all([...new Set([...walls, 'door', 'sprite'])].map(writeTexture));
  return src;
}

function renderSource(src, px, py) {
  const lines = src.split('\n');
  const first = lines.findIndex((l) => /^[\s012NSEW]*[01][\s012NSEW]*$/.test(l) && l.includes('1'));
  return lines.map((line, i) => {
    const row = i - first;
    if (row !== Math.floor(py) || row < 0) return escapeHtml(line);
    const col = Math.floor(px);
    return escapeHtml(line.slice(0, col))
      + `<mark>${escapeHtml(line[col] ?? ' ') === ' ' ? '&nbsp;' : escapeHtml(line[col])}</mark>`
      + escapeHtml(line.slice(col + 1));
  }).join('\n');
}
const escapeHtml = (s) => (s ?? '').replace(/[&<>]/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;' }[c]));

let source = '';
function paintSource() {
  $('#source').innerHTML = renderSource(source, M.ccall('cw_player_x', 'number', [], []),
                                                M.ccall('cw_player_y', 'number', [], []));
}

// Renders only while something is changing.
//
// The engine already works this way - cb_start_game.c's loop hook sits behind
// a data->update_win dirty flag - so a standing player costs nothing. A
// requestAnimationFrame loop that never stops would undo that and keep a
// portfolio page burning battery in a background tab for as long as it is open.
function frame() {
  pending = false;
  if (!ready) return;
  for (const code of held) M.ccall('cw_key', null, ['number'], [KEY[code]]);
  M.ccall('cw_frame_rgba', null, [], []);
  const p = M.ccall('cw_buffer', 'number', [], []);
  image.data.set(M.HEAPU8.subarray(p, p + W * H * 4));
  ctx.putImageData(image, 0, 0);
  paintSource();
  if (held.size) schedule();                 // keep going while a key is down
}

function schedule() {
  if (pending || !ready) return;
  pending = true;
  requestAnimationFrame(frame);
}

async function start(name) {
  ready = false;
  if (M.ccall) M.ccall('cw_destroy', null, [], []);
  $('#status').textContent = 'loading…';
  source = await loadMap(name);
  if (M.ccall('cw_init', 'number', ['string'], [`maps/${name}.cub`]) !== 0) {
    $('#status').textContent = 'this map failed to load';
    return;
  }
  W = M.ccall('cw_width', 'number', [], []);
  H = M.ccall('cw_height', 'number', [], []);
  canvas.width = W; canvas.height = H;
  image = ctx.createImageData(W, H);
  currentMap = name;
  history.replaceState(null, '', `?map=${name}`);
  document.querySelectorAll('.tab').forEach((b) => b.setAttribute('aria-pressed', String(b.dataset.map === name)));
  $('#status').textContent = 'click the view, then walk';
  ready = true;
  schedule();
}

addEventListener('keydown', (e) => {
  if (document.activeElement !== canvas) return;       // the page keeps its keys
  if (HELD.has(e.code)) {
    held.add(e.code);
    e.preventDefault();
    // Also step once now. A quick tap can start and end between two frames,
    // and a key that does nothing unless held reads as a broken demo.
    schedule();
  } else if (TAP.has(e.code)) {
    M.ccall('cw_key', null, ['number'], [KEY[e.code]]);
    e.preventDefault();
    schedule();
  }
});
addEventListener('keyup', (e) => held.delete(e.code));
canvas.addEventListener('blur', () => { held.clear(); $('#status').textContent = 'click the view, then walk'; });
canvas.addEventListener('focus', () => { $('#status').textContent = 'walking — press Esc… or click away to give the page its keys back'; });

M = await Cub3d();
try { M.FS.mkdir('maps'); } catch {}
try { M.FS.mkdir('rgba'); } catch {}
document.querySelectorAll('.tab').forEach((b) => b.addEventListener('click', () => { start(b.dataset.map); canvas.focus(); }));
await start(currentMap);
