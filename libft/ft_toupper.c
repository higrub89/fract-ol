/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:20:55 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/02 22:40:18 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - ('a' - 'A');
	}
	return (c);
}
/*
int	main()
{
	char	c = 'b';

	char r =  ft_toupper(c);
	printf("caracter normal: %c\n", c);
	printf("caracter convertido: %c\n", r);

	return (0);
}*/
