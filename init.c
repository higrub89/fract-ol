/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:08:51 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/27 21:09:06 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_data *data)
{
	data->escape_value = 4;
	data->itera = 50;
	data->change_x = 0.285;
	data->change_y = 0.01;
	data->zoom = 1.0;
}

static void	events_init(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_handler,
		data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, julia, data);
}

void	fractal_init(t_data *data)
{
	data->mlx = mlx_init();
	if (NULL == data->mlx)
		malloc_error();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGTH, data->name);
	if (NULL == data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	if (NULL == data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.pixel = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	events_init(data);
	data_init(data);
}
