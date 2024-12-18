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
	t_scale	scale_iter = {0, max_iter, BLACK, WHITE};
	return (int)map(i, &scale_iter);
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

	// Definir el escalado para x e y
	t_scale scale_x = {0, WIDTH, -2, 2};  // Escalar x de 0 a width a [-2, 2]
	t_scale scale_y = {0, HEIGTH, 2, -2}; // Escalar y de 0 a height a [2, -2]
	i = 0;
	// Escalar las coordenadas de x e y
	z.x = map(x, &scale_x) * data->zoom + data->change_x;
	z.y = map(y, &scale_y) * data->zoom + data->change_y;
	// Llamar a la función para determinar el conjunto Mandelbrot o Julia
	mandelbrot_or_julia(&z, &c, data);
	// Iteración para verificar si el punto escapa del conjunto
	while (i < data->itera)
	{
		z = sum_complex(square_complex(z), c);
		// Verificar si el valor escapa (es mayor que 4)
		if ((z.x * z.x) + (z.y * z.y) > data->escape_value)
		{
			// Obtener el color usando la función get_color_itera
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

	// Iterar sobre cada píxel de la imagen
	y = -1;
	while (++y < HEIGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, data);
		}
	}
	// Mostrar la imagen renderizada en la ventana
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
