/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthuy <pthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:16:39 by pthuy             #+#    #+#             */
/*   Updated: 2019/10/08 22:49:44 by pthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define MAX_FD 4096

# include <fcntl.h>
# include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);
int		end_line(const int fd, char **line, char **table);
void	clear_swap(char **table, char *ptr);

#endif
