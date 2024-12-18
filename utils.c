/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:44:48 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/24 11:53:33 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	validate_julia_coordinates(double x, double y)
{
	if (x < -2.0 || x > 2.0 || y < -2.0 || y > 2.0)
	{
		ft_putstr_fd("INVALID COORDINATES\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	handle_julia(int argc, char **argv, t_data *data)
{
	if (argc != 4 || ft_strncmp(argv[1], "julia", 5))
		return ;
	data->name = argv[1];
	data->jul_x = atodbl(argv[2]);
	data->jul_y = atodbl(argv[3]);
	validate_julia_coordinates(data->jul_x, data->jul_y);
}

void	handle_mandelbrot(int argc, char **argv, t_data *data)
{
	if (argc != 2 || ft_strncmp(argv[1], "mandelbrot", 10))
		return ;
	data->name = argv[1];
}
