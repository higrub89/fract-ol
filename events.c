/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:08:31 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/27 22:03:26 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img_ptr);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
		close_handler(data);
	if (keysym == XK_Left)
		data->change_x += (0.5 * data->zoom);	
	else if (keysym == XK_Right)
		data->change_x -= (0.5 * data->zoom);	
	else if (keysym == XK_Up)
		data->change_y -= (0.5 * data->zoom);
	else if (keysym == XK_Down)
		data->change_y += (0.5 * data->zoom);	
	else if (keysym == XK_plus)
		data->itera += 10;
	else if (keysym == XK_minus)	
		data->itera -= 10;

	// refresh the image
	fractal_render(data);
	return 0;
}

int mouse_handler(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	//Zoom in
	if (button == Button5)
	{
		data->zoom *= 0.95;
	}
	//Zoom out
	else if (button == Button4)
	{
		data->zoom *= 1.05;
	}
	// refresh
	fractal_render(data);
	return 0;
}

int julia(int x, int y, t_data *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		data->jul_x = (scale(x, -2, +2, 0, WINDOW_WIDTH) * data->zoom) + data->change_x;
		data->jul_y = (scale(y, +2, -2, 0, WINDOW_HEIGTH) * data->zoom) + data->change_y;
		fractal_render(data);
	}
	return 0;
}
