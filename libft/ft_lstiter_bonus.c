/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:06 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:19 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*n;

	if (lst && f)
	{
		n = lst;
		while (n)
		{
			f(n->content);
			n = n->next;
		}
	}
}
/*
void	f(void *content)
{
	char	*p;

	p = (char *)content;
	while (*p)
	{
		*p = *p - 32;
		printf("%c\n", *p);
		p++;
	}
}*/
