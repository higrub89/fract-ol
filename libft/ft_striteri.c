/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:05:47 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/12 03:27:49 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f(unsigned int i, char *s)
{
	printf("posicion: s[%i] = %s\n", i, s);
}

int	main(void)
{
	char	*s = "Bienvenidos a 42 madrid";
	ft_striteri(s, f);
	return (0);
}*/
