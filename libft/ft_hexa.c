/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:20:05 by rhiguita          #+#    #+#             */
/*   Updated: 2024/06/09 16:27:07 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexa_upper(unsigned long n, int *i)
{
	char			*base;
	unsigned int	num;
	unsigned int	len_b;

	base = "0123456789ABCDEF";
	num = (unsigned int)n;
	len_b = ft_strlen(base);
	if (num >= 16)
	{
		ft_hexa_upper(num / len_b, i);
	}
	ft_putchar_count(*(base + (num % len_b)), i);
}

void	ft_hexa_low(unsigned long n, int *i)
{
	char			*base;
	unsigned int	num;
	unsigned int	len_b;

	base = "0123456789abcdef";
	num = (unsigned int)n;
	len_b = ft_strlen(base);
	if (num >= 16)
	{
		ft_hexa_low(num / len_b, i);
	}
	ft_putchar_count(*(base + (num % len_b)), i);
}
