/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:19:20 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/12 03:28:30 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char	f(unsigned int i, char s)
{
	printf("Posicion del string:  s[%d] = %c\n", i, s);
	return (s - 32);
}

int	main(void)
{
	char	*s = "bienvenidos a 42 madrid";
	printf("Original: %s\n\n", s);

	char	*r = ft_strmapi(s, f);
	printf("\nModificada: %s\n", r);
	return (0);
}*/
