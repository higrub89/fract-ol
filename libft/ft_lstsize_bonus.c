/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:59:19 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/12 18:44:09 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main(void)
{
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	int	n4 = 4;

	t_list	*list	= ft_lstnew(&n1);

	ft_lstadd_front(&list, ft_lstnew(&n2));
	ft_lstadd_front(&list, ft_lstnew(&n3));
	ft_lstadd_front(&list, ft_lstnew(&n4));

	int	size = ft_lstsize(list);
	printf("numero de nodos en la lista: %i\n", size);

	return (0);
}*/
