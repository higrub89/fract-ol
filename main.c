/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:40:02 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/18 20:12:06 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		handle_mandelbrot(argc, argv, &data);
	}
	else if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		handle_julia(argc, argv, &data);
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
