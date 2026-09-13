// Spike harness: boot the module, render, report median frame time.
// Usage: node wasm/bench.mjs <map.cub> [frames]
import Cub3d from './cub3d.js';

const map = process.argv[2] ?? 'maps/metal.cub';
const frames = Number(process.argv[3] ?? 200);

const M = await Cub3d();
const init = M.cwrap('cw_init', 'number', ['string']);
if (init(map) !== 0) { console.error(`cw_init failed on ${map}`); process.exit(1); }

const w = M.ccall('cw_width', 'number', [], []);
const h = M.ccall('cw_height', 'number', [], []);

// Warm up: first frames pay for lazy compilation and cold caches.
M.ccall('cw_bench', 'number', ['number'], [20]);

const still   = M.ccall('cw_bench',         'number', ['number'], [frames]);
const walking = M.ccall('cw_bench_walking', 'number', ['number'], [frames]);

console.log(JSON.stringify({ map, w, h, frames,
  still_ms: +still.toFixed(3), walking_ms: +walking.toFixed(3) }));
// Reports cw_height alongside the timings, because a -D override that the
// header silently wins over is invisible otherwise: the build renders 400,
// reports 600 in the table, and the numbers look merely optimistic.
