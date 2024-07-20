/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:48:18 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/11 21:36:48 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	r_a_b(t_list *list)
{
	t_list	*tmp;
	t_list	*top;

	if (!list || !list->next)
		return ;
	tmp = list;
	list = list->next;
	top = list;
	while (top != NULL)
	{
		top = top->next;
	}
	top = tmp;
}

void	rr(t_list *list_a, t_list *list_b)
{
	r_a_b(list_a);
	r_a_b(list_b);
	ft_putstr("rr\n");
}

t_list	*rrr_a_b(t_list *list)
{
	t_list	*tmp;
	t_list	*top;

	if (!list || !list->next)
		return (list);
	tmp = list;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	top = tmp->next;
	tmp->next = tmp->next->next;
	top->next = list;
	list = top;
	return (list);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	*list_a = rrr_a_b(*list_a);
	*list_b = rrr_a_b(*list_b);
	ft_putstr("rrr\n");
}

void	ss_a_b(t_list *list)
{
	int	tmp;

	if (!list || !list->next)
		return ;
	tmp = list->data;
	list->data = list->next->data;
	list->next->data = tmp;
}
