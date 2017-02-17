/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:25:28 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 20:25:30 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <string.h>

# define BUFF_SIZE 1024

typedef struct				s_gnl
{
	int						fd;
	char					*str;
	char					*tmp;
	char					*line;
	size_t					len;
	size_t					len_old;
	size_t					i;
	char					eof;
	char					start;
	char					stop;
	char					lf;
	struct s_gnl			*next;
	struct s_gnl			*prev;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
