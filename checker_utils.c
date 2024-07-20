/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:37:14 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/11 21:37:14 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
		i++;
	return (str1[i] - str2[i]);
}

t_list	*create_stack2(int argc, char **argv)
{
	int		i;
	t_list	*tmp;
	t_list	*before;
	t_list	*head;

	before = 0;
	i = 1;
	while (i < argc)
	{
		tmp = malloc(sizeof(t_list));
		tmp->data = ft_atoi(argv[i]);
		if (i == 1)
			head = tmp;
		if (before != 0)
			before->next = tmp;
		before = tmp;
		i++;
	}
	tmp->next = NULL;
	return (head);
}

void	check_duplicate2(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;
	while (i)
	{
		j = argc - 1;
		while (j)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
			{
				ft_putstr_error("Error\n");
				exit(1);
			}
			j--;
		}
		i--;
	}
}

void	check_error_checker(int argc, char **argv)
{
	check_is_digit(argc, argv);
	check_duplicate2(argc, argv);
}
