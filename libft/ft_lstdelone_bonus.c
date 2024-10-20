/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:49:18 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 15:45:11 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	ft_print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("Contenido del nodo: %s\n", (char *)(lst->content));
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	int 	cont;
	t_list	*lst;

	cont = 1;
	lst = NULL;
	while (cont < argc)
	{
		ft_lstadd_back(&lst, ft_lstnew(argv[cont++]));
	}
	ft_print_list(lst);

	while (lst != NULL)
	{
		t_list *t = lst->next;
		ft_lstdelone(lst, free);
	}

	return (0);
}*/
