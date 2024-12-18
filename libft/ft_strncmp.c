/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:13:58 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/16 20:10:45 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*a = "Hola Mundo!";
	const char 	*b = "Holla Mundo!";

	int	result = ft_strncmp(a, b, 10);
	printf("Comparamos los strings 'a' y 'b': %i\n", result);
	return (0);
}*/
