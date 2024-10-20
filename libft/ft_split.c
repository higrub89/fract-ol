/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:38:49 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/12 03:30:03 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lengh(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			s += ft_lengh(s, c);
		}
		else
			s++;
	}
	return (word);
}

static void	*ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count_word;
	size_t	i;

	if (!s)
		return (NULL);
	count_word = ft_count_word(s, c);
	ptr = malloc(sizeof(char *) * (count_word + 1));
	if (!ptr)
		return (NULL);
	ptr[count_word] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ptr[i] = ft_substr(s, 0, ft_lengh(s, c));
			if (!ptr[i++])
				return (ft_free(ptr));
			s += ft_lengh(s, c);
		}
		else
			s++;
	}
	return (ptr);
}
/*
int	main(void)
{
	char	*s = "Bienvenidos a 42 madrid ";
	char	c = ' ';

	char	**r = ft_split(s, c);
	if (r)
	{
		int	i;

		i = 0;
		while (r[i])
		{
			printf("Palara %d: %s\n", i + 1, r[i]);
			i++;
		}
		ft_free(r);
	}
	return (0);
}*/
