/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:37:01 by aachaq            #+#    #+#             */
/*   Updated: 2022/12/11 21:37:01 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*current_line(char *rest)
{
	int	i;

	i = 0;
	if (!rest[0])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	return (ft_substr(rest, 0, i + 1));
}

char	*next_line(char *rest)
{
	int		i;
	char	*s;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			s = ft_substr(rest, i + 1, ft_strlen(rest) - i);
			free(rest);
			return (s);
		}
		i++;
	}
	free(rest);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				bufsize;
	char			buff[11];
	static char		*rest;
	char			*line;
	int				j;

	bufsize = 10;
	j = 1;
	line = NULL;
	if (fd < 0 || bufsize <= 0)
		return (0);
	while (j && ft_strchr(rest))
	{
		j = read(fd, buff, bufsize);
		if (j == -1)
			return (line);
		buff[j] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	line = current_line(rest);
	rest = next_line(rest);
	return (line);
}
