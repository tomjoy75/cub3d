/* Minimal MiniLibX surface, for the WebAssembly build only.
 *
 * MiniLibX is X11-based and cannot be built for the browser. It does not need
 * to be: the thirteen entry points below are the entire surface this project
 * uses, and t_img is plain data — a width, a height, a bytes-per-pixel and a
 * pointer. Everything downstream of cb_image_load() does pointer arithmetic on
 * that pointer, so the renderer compiles unchanged against a buffer we own.
 *
 * Nothing here emulates X11. The window is a fiction, the event loop is driven
 * from JavaScript, and mlx_put_image_to_window is a no-op because the canvas
 * reads the buffer directly.
 */
#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx, int w, int h, char *title);
void	*mlx_new_image(void *mlx, int w, int h);
char	*mlx_get_data_addr(void *img, int *bpp, int *line_len, int *endian);
void	*mlx_xpm_file_to_image(void *mlx, char *path, int *w, int *h);
int		mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y);
int		mlx_destroy_image(void *mlx, void *img);
int		mlx_destroy_window(void *mlx, void *win);
int		mlx_destroy_display(void *mlx);
int		mlx_hook(void *win, int event, int mask, int (*f)(), void *param);
int		mlx_loop_hook(void *mlx, int (*f)(), void *param);
int		mlx_loop(void *mlx);
int		mlx_mouse_hide(void *mlx, void *win);
int		mlx_mouse_get_pos(void *mlx, void *win, int *x, int *y);

#endif
