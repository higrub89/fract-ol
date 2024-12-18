/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:09:27 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/27 21:09:32 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel + offset) = color;
}

int	get_color_itera(int i, int max_iter)
{
	t_scale	scale_iter;

	scale_iter = (t_scale){0, max_iter, BLACK, NEON_YELLOW};
	return ((int)map(i, &scale_iter));
}

static void	mandelbrot_or_julia(t_complex *Z, t_complex *C, t_data *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		C->x = data->jul_x;
		C->y = data->jul_y;
	}
	else
	{
		C->x = Z->x;
		C->y = Z->y;
	}
}

static void	handle_pixel(int x, int y, t_data *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = map(x, &(t_scale){0, WIDTH, -2, 2}) * data->zoom + data->change_x;
	z.y = map(y, &(t_scale){0, HEIGTH, 2, -2}) * data->zoom + data->change_y;
	mandelbrot_or_julia(&z, &c, data);
	while (i < data->itera)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > data->escape_value)
		{
			color = get_color_itera(i, data->itera);
			my_pixel_put(x, y, &data->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &data->img, WHITE);
}

void	fractal_render(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, data);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
