/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:44:01 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 16:14:37 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	int	data1 = 42;
	int	data2 = 12;
	int	data3 = 14;
	int	data4 = 16;

	t_list *list = ft_lstnew(&data1);

	ft_lstadd_front(&list, ft_lstnew(&data2));
	ft_lstadd_front(&list, ft_lstnew(&data3));
	ft_lstadd_front(&list, ft_lstnew(&data4));

	t_list	*last = ft_lstlast(list);

	printf("Contenido del ultimo nodo: %d\n", *(int *)(last->content));
	return (0);
}*/
