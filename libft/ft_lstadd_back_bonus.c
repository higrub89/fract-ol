/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:19:21 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 11:29:15 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
/*
int	main(void)
{
	t_list	*list = ft_lstnew("node one");

	ft_lstadd_back(&list, ft_lstnew("node two"));
	ft_lstadd_back(&list, ft_lstnew("node tw o"));
	ft_lstadd_back(&list, ft_lstnew("node two"));

	printf("ultimo nodo: %s\n", (char *)(list->content));
	return (0);
}*/
