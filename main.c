/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:40:02 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/15 13:23:46 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		data.name = argv[1];
	}
	else if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		data.name = argv[1];
		if (!ft_strncmp(data.name, "julia", 5))
		{
			data.jul_x = atodbl(argv[2]);
			data.jul_y = atodbl(argv[3]);
			if (data.jul_x < -2.0 || data.jul_x > 2.0 || data.jul_y < -2.0
				|| data.jul_x > 2.0)
			{
				ft_putstr_fd("INVALID COORDINATES\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_init(&data);
	fractal_render(&data);
	mlx_loop(data.mlx);
}
