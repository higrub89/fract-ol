/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:50 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/04 23:12:53 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size && dest[i])
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int	main()
{
	const char s[] = "Mundo!";
	char d[15] = "Hola ";
	size_t r = ft_strlcat(d, s, sizeof(d));

	printf("cadena Concatenada: %s\n", d);
	printf("Longitud de la cadena Concatenada: %zu\n", r);

	return (0);
}*/
