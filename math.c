/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:36:26 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/18 20:14:13 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double num, t_scale *scale)
{
	return ((scale->new_max - scale->new_min) * (num - scale->old_min)
		/ (scale->old_max - scale->old_min) + scale->new_min);
}

t_complex	sum_complex(t_complex Z1, t_complex Z2)
{
	t_complex	result;

	result.x = Z1.x + Z2.x;
	result.y = Z1.y + Z2.y;
	return (result);
}

t_complex	square_complex(t_complex Z)
{
	t_complex	result;

	result.x = (Z.x * Z.x) - (Z.y * Z.y);
	result.y = 2 * Z.x * Z.y;
	return (result);
}
