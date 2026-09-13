#!/bin/sh
# The shippable build: no embedded assets.
#
# wasm/build.sh embeds maps/ and rgba/ into the binary, which is fine for
# measuring and useless for shipping - it produces a 26 MB .wasm. Here the
# page fetches the .cub and the textures itself and writes them into the
# virtual filesystem before cw_init, so the binary carries only code.
set -e
W=${W:-800}; H=${H:-600}; OUT=${OUT:-web/cub3d.js}
mkdir -p "$(dirname "$OUT")"
# shellcheck disable=SC2086
emcc -O3 -flto $(ls srcs/*.c) wasm/mlx_shim.c wasm/cub3d_wasm.c $(ls libft/srcs/*.c) \
	-I includes -I libft -I wasm \
	-D CB_BONUS_ENABLED=1 -D CB_WIN_W=$W -D CB_WIN_H=$H \
	-s EXPORTED_FUNCTIONS='["_cw_init","_cw_destroy","_cw_frame","_cw_frame_rgba","_cw_key","_cw_player_x","_cw_player_y","_cw_buffer","_cw_width","_cw_height","_malloc","_free"]' \
	-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","FS","HEAPU8"]' \
	-s ALLOW_MEMORY_GROWTH=1 -s FORCE_FILESYSTEM=1 \
	-s MODULARIZE=1 -s EXPORT_ES6=1 -s EXPORT_NAME=Cub3d -s ENVIRONMENT=web \
	-o "$OUT"
ls -l "${OUT%.js}.wasm" "$OUT"
