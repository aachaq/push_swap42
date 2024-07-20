/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:18:06 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/15 22:19:47 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_digit(int argc, char **argv)
{
	int	i;

	while (--argc)
	{
		i = 0;
		while (argv[argc][i])
		{
			if ((argv[argc][i] < '0' || argv[argc][i] > '9')
					&& argv[argc][i] != '-' && argv[argc][i] != '+')
			{
				ft_putstr_error("Error\n");
				exit(1);
			}
			i++;
		}
	}
}

void	check_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_error("Error\n");
			exit(1);
		}
		i++;
	}
}

void	check_duplicate(int argc, char **argv)
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

int	check_sort(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		exit (0);
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	exit (0);
}

void	check_error(int argc, char **argv)
{
	check_empty_arg(argv);
	check_is_digit(argc, argv);
	check_duplicate(argc, argv);
	check_sort(argc, argv);
}
