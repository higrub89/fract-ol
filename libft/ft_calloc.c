/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:19:09 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 22:41:46 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	num_bytes;

	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_bytes);
	return (ptr);
}
/*
int	main()
{
	size_t	a = 5;
	size_t	b = sizeof(int);
	int *ab = (int *)ft_calloc(a, b);

	int	i;

	i = 0;
	while (i < 5)
	{
		printf("ab[%i]=%d\n", i, *ab);
		i++;
	}
	return (0);
}*/
