#include "fractol.h"

void	draw_julia(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;

	c.r = -0.7;
	c.i = 0.27015;
	z.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	z.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	ft_put_pixel(data->img, x, y, calc_bright(&z, &c, data));
}
