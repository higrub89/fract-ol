/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:01:55 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/18 21:49:27 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	size;

	len = ft_strlen(s1);
	i = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[len]) && len)
		len--;
	size = len - i + 1;
	return (ft_substr(s1, i, size));
}
/*
int	main()
{
	char const	*a = "! Welcome to Madrid !";
	char const	*b = " !";
	char		*r = ft_strtrim(a, b);

	printf("String Antes: %s\n", a);
	printf("String Despues: %s\n", r);

	return (0);
}*/
