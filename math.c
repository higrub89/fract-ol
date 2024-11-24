/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:36:26 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:39 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//rescaledValue = ((new_max - new_min) * (unscaledNum - old_min)) / (old_max - old_min) + new_min
// Solution scaled = (0,799) -> (-2,+2);
double  scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

// SUM complex;
t_complex   sum_complex(t_complex Z1, t_complex Z2)
{
    t_complex   result;
    
    result.x = Z1.x + Z2.x;
    result.y = Z1.y + Z2.y;
    return (result);
}

// square comlex;
    // real = (R² - I²)
    // Imaginarry = 2*R*I
t_complex   square_complex(t_complex Z)
{
    t_complex   result;

    result.x = (Z.x * Z.x) - (Z.y * Z.y);
    result.y = 2 * Z.x * Z.y;
    return (result);
}