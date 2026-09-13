/* Measurement variant: column drawing removed, DDA traversal kept.
 *
 * Built only by NO_DRAW=1 in wasm/build.sh. The difference between this
 * build's frame time and the full build's is the cost of texture sampling and
 * the ceiling/floor fill — the part a lower resolution or a flat-colour
 * fallback would actually save.
 *
 * The volatile sink is load-bearing. With a genuinely empty cb_draw_line,
 * -O3 -flto proves the raycast has no observable effect and deletes it, and
 * the build reports 0.000 ms for work it never did. Consuming the results
 * keeps the traversal alive. Never shipped.
 */
#include "cb_data.h"
#include "cb_graphics.h"
#include "cb_graphics_utils.h"

volatile int	g_sink;

void	cb_draw_line(t_data *data, t_img *img, t_rcline *line)
{
	(void)img;
	g_sink += line->pos_x + line->draw_top + line->draw_bottom
		+ line->texture_x + data->win_height;
}
