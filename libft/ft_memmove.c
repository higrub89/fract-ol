/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:35:52 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/02 14:05:59 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src <= dest && dest < src + n)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Welcome to 42 Madrid!";
	char	dest[30];
	ft_memmove(dest, src, 17);
	dest[17] = '\0'; 
	printf("Bloque de Memoria copiado: %s\n", dest);

	ft_memmove(src + 5, src, 8);
	//memmove(src + 5, src, 10);
	printf("Bloque de Memoria superpuesto: %s\n", src);

	int	source[] = {1, 2, 3, 4, 5, 6};
	int	destination[6];
	ft_memmove(destination, source, sizeof(int) * 6);

	int	i = 0;
	while (i < 6)
	{
		printf("Vector copiado: [%d]=%d\n", i, (int)destination[i]);
		i++;
	}
	return (0);
}*/
