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

/*
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (NULL == s1  || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}
*/
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
