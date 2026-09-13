#!/bin/sh
# Builds the browser target. Run from the repository root: sh wasm/build.sh
#
# W= and H= override the render size; defaults match the native build
# (cb_constants.h), which is 800x400.
#
# NO_DRAW=1 builds a variant whose column drawing is a no-op, so that
# subtracting its frame time from the full build's isolates the DDA traversal
# from texture sampling. Measurement only — it renders nothing.
set -e

W=${W:-800}
H=${H:-400}
BONUS=${BONUS:-1}
OUT=${OUT:-wasm/cub3d.js}

SRC="$(ls srcs/*.c) wasm/mlx_shim.c wasm/cub3d_wasm.c $(ls libft/srcs/*.c)"

if [ "${NO_DRAW:-0}" = "1" ]; then
	SRC="$(echo "$SRC" | tr ' ' '\n' | grep -v 'cb_draw_line\.c') wasm/no_draw.c"
fi

# shellcheck disable=SC2086
emcc -O3 -flto $SRC \
	-I includes -I libft -I wasm \
	-D CB_BONUS_ENABLED=$BONUS \
	-D CB_WIN_W=$W -D CB_WIN_H=$H \
	-s EXPORTED_FUNCTIONS='["_cw_init","_cw_destroy","_cw_frame","_cw_key","_cw_buffer","_cw_width","_cw_height","_cw_bench","_cw_bench_walking","_malloc","_free"]' \
	-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPU8"]' \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s MODULARIZE=1 -s EXPORT_NAME=Cub3d \
	--embed-file maps \
	--embed-file data \
	--embed-file rgba \
	-o "$OUT"

ls -l "${OUT%.js}.wasm" "$OUT"
