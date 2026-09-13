/* The X11 keysyms this project matches on, with their real values.
 *
 * Kept real rather than renumbered so srcs/cb_start_game.c compiles untouched
 * and the browser can dispatch into it by sending the same numbers X would.
 */
#ifndef CB_WASM_KEYSYM_H
# define CB_WASM_KEYSYM_H

# define XK_Escape 0xff1b
# define XK_Left   0xff51
# define XK_Right  0xff53
# define XK_space  0x0020
# define XK_a      0x0061
# define XK_A      0x0041
# define XK_d      0x0064
# define XK_D      0x0044
# define XK_m      0x006d
# define XK_M      0x004d
# define XK_s      0x0073
# define XK_S      0x0053
# define XK_w      0x0077
# define XK_W      0x0057

#endif
