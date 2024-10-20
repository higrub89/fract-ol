/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:41:53 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/02 14:07:27 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	*srcs = "Bienvenidos a 42 Madrid!";
	char	dest[30];
	ft_memcpy(dest, srcs, 15);
	dest[15] = '\0';

	printf("Bloque de memoria copiado: %s\n", dest);
	return (0);
}*/
