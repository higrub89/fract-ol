/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:52:15 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/12 18:37:43 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
/*
int	main(void)
{
	t_list	*node1 = ft_lstnew("Nodo existente");
	t_list	*node2 = ft_lstnew("Nuevo nodo");


	ft_lstadd_front(&node1, node2);

	printf("contenido: %s\n", (char *)(node2->content));

	return (0);
}*/
