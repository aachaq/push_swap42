/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:36:37 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/11 21:36:37 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	index_position(t_list *stack, int index)
{
	int	position;

	position = 1;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
}
