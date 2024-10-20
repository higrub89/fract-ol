/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:37:22 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/11 22:25:47 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_num(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	if (n < 0)
		num = -n;
	size = size_num(n);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	size--;
	if (num == 0)
		ptr[size] = '0';
	while (num > 0)
	{
		ptr[size--] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		ptr[size] = '-';
	return (ptr);
}
/*
int	main()
{
	int	num = 123452;
	char	*s = ft_itoa(num);

	printf("Conevertimos el numero de entero a string:\n%s\n", s);
	return (0);
}*/
