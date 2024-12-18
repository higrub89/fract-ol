/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:41:39 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/02 22:50:58 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
/*
int	main()
{
	char c = 'F';
	char r = ft_tolower(c);

	printf("Caracter Normal: %c\n", c);
	printf("Caracter Convertido: %c\n", r);

	return (0);
}*/
