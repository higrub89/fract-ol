/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:08:02 by rhiguita          #+#    #+#             */
/*   Updated: 2024/06/09 18:08:45 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsig_putnbr(unsigned int n, int *i)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		n %= 10;
	}
	ft_putchar_count(n + '0', i);
}
