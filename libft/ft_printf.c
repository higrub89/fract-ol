/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:36:00 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/06 12:37:43 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	parse_format(const char *str, t_list **head)
{
	char	*text;

	while (*str)
	{
		text = malloc(2);
		text[0] = *str;
		text[1] = '\0';
		ft_lstadd_back(head, ft_lstnew(text));
		str++;
	}
}

static void	handle_format(t_list *head, va_list args, int *i)
{
	if (!head || !head->content)
		return ;
	if ((*(head)->content) == 's')
		ft_putstr(va_arg(args, char *), i);
	else if ((*(head->content)) == 'c')
		ft_putchar_count(va_arg(args, int), i);
	else if ((*(head->content)) == 'd')
		ft_putnbr(va_arg(args, int), i);
	else if ((*(head->content)) == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if ((*(head->content)) == 'u')
		ft_unsig_putnbr(va_arg(args, unsigned int), i);
	else if ((*(head->content)) == 'p')
		ft_pointer(va_arg(args, void *), i);
	else if ((*(head->content)) == 'x')
		ft_hexa_low(va_arg(args, unsigned long), i);
	else if ((*(head->content)) == 'X')
		ft_hexa_upper(va_arg(args, unsigned long), i);
	else if ((*(head->content)) == '%')
		ft_putchar_count('%', i);
	else
	{
		ft_putchar_count('%', i);
		ft_putstr((char *)head->content, i);
	}
}

static void	process_node(t_list *head, va_list args, int *i)
{
	while (head)
	{
		if (*((char *)(head->content)) == '%')
		{
			head = head->next;
			handle_format(head, args, i);
		}
		else
			ft_putstr((char *)head->content, i);
		head = head->next;
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	t_list	*head;
	int		len;

	head = NULL;
	len = 0;
	parse_format(str, &head);
	va_start(args, str);
	process_node(head, args, &len);
	va_end(args);
	ft_lstclear(&head, free);
	return (len);
}
