/* The X11 event and mask constants this project passes to mlx_hook. */
#ifndef CB_WASM_X_H
# define CB_WASM_X_H

# define KeyPress            2
# define MotionNotify        6
# define DestroyNotify       17
# define KeyPressMask        (1L << 0)
# define PointerMotionMask   (1L << 6)
# define StructureNotifyMask (1L << 17)

#endif
