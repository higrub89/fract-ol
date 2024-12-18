/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:01:00 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/06 22:20:04 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
int	main()
{	
	int	fd = open ("file.txt", O_RDWR | O_CREAT);
	char	s[25] = "Welcome";
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
}*/
