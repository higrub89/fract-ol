/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:44:32 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/06 16:47:37 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_pointer(unsigned long n, char *base, int *i)
{
	if (n > (unsigned long)(ft_strlen(base) - 1))
		print_pointer(n / ft_strlen(base), base, i);
	ft_putchar_count(*(base + (n % ft_strlen(base))), i);
}

void	ft_pointer(void *format, int *i)
{
	char			*base;
	unsigned long	num;

	num = (unsigned long)format;
	base = "0123456789abcdef";
	if (format == NULL)
	{
		ft_putstr("(nil)", i);
		return ;
	}
	ft_putstr("(0x)", i);
	print_pointer(num, base, i);
}
