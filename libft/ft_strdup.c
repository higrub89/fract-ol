/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:38:58 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/18 22:38:55 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main()
{
	const char	*s = "Welcome to Madrid 42";
	char		*r = ft_strdup(s);
	
	printf("string duplicado: %s\n", r);
	return (0);	
}*/
