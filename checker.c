/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:37:11 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/11 21:37:11 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_checker(t_list **list_a, t_list **list_b)
{
	*list_a = rrr_a_b(*list_a);
	*list_b = rrr_a_b(*list_b);
}

void	check_instrection(t_list **stack_a, t_list **stack_b, char *instr)
{
	if (ft_strncmp(instr, "sa\n", 3) == 0)
		s(stack_a, '0');
	else if (ft_strncmp(instr, "sb\n", 3) == 0)
		s(stack_b, '0');
	else if (ft_strncmp(instr, "ra\n", 3) == 0)
		r(stack_a, '0');
	else if (ft_strncmp(instr, "rb\n", 3) == 0)
		r(stack_b, '0');
	else if (ft_strncmp(instr, "rra\n", 4) == 0)
		rr_a_b(stack_a, '0');
	else if (ft_strncmp(instr, "rrb\n", 4) == 0)
		rr_a_b(stack_b, '0');
	else if (ft_strncmp(instr, "pa\n", 3) == 0)
		p(stack_a, stack_b, '0');
	else if (ft_strncmp(instr, "pb\n", 3) == 0)
		p(stack_b, stack_a, '0');
	else if (ft_strncmp(instr, "rrr\n", 4) == 0)
		rrr_checker(stack_a, stack_b);
	else
		ft_putstr_error("Error\n");
}

int	check_sort_checker(t_list *stack_a)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	checker_sort(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(0);
	while (line)
	{
		check_instrection(stack_a, stack_b, line);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "\n", 1) == 0)
			break ;
	}
	i = check_sort_checker(*stack_a);
	if (i == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		check_error_checker(argc, argv);
		stack_a = create_stack2(argc, argv);
		checker_sort(&stack_a, &stack_b);
	}
	else
		return (0);
	return (0);
}
