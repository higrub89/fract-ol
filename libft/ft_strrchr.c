/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:25:22 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 21:38:40 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
int	main(void)
{
	char	*s = "Welcome to 42 Madrid";
	char	c = 'e';

	char	*r = ft_strrchr(s, c);
	printf("Ultima ocurrencia: %s\n", r);
	return (0);
}*/
