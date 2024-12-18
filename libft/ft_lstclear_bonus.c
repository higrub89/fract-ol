/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:17:40 by rhiguita          #+#    #+#             */
/*   Updated: 2024/05/15 19:54:53 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			tem = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tem;
		}
	}
}
