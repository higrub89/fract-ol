/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:08:46 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 22:48:02 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (size <= start)
		return (ft_calloc(1, sizeof(char)));
	i = size - start;
	if (i < len)
		len = i;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s[start], len + 1);
	return (p);
}
/*
int	main()
{
	char const	*s = "Welcome to 42 Madrid";
	char		*r = ft_substr(s, 11, 5);

	printf("Substring del string '%s' es: %s\n", s, r);
	free(r);
	return (0);
}*/
