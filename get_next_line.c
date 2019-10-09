/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthuy <pthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:16:29 by pthuy             #+#    #+#             */
/*   Updated: 2019/10/08 22:36:27 by pthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char static	*table[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			bytes;

	if (BUFF_SIZE < 1 || fd > MAX_FD || fd < 0 || !line)
		return (-1);
	if (table[fd] == NULL)
		table[fd] = ft_strnew(0);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		tmp = ft_strjoin(table[fd], buf);
		clear_swap(&table[fd], tmp);
		if (ft_strchr(table[fd], '\n'))
			break ;
	}
	if (bytes == 0 && table[fd][0] == '\0')
	{
		clear_swap(&table[fd], NULL);
		return (0);
	}
	return (bytes < 0 ? -1 : end_line(fd, line, table));
}

int		end_line(const int fd, char **line, char **table)
{
	char	*tmp;
	int		i;

	i = 0;
	while (table[fd][i] != '\n' && table[fd][i] != '\0')
		i++;
	if (table[fd][i] == '\n')
	{
		*line = ft_strsub(table[fd], 0, i);
		tmp = ft_strdup(table[fd] + i + 1);
		clear_swap(&table[fd], tmp);
	}
	else if (table[fd][i] == '\0')
	{
		*line = ft_strdup(table[fd]);
		clear_swap(&table[fd], NULL);
	}
	return (1);
}

void	clear_swap(char **table, char *ptr)
{
	free(*table);
	*table = ptr;
}
