/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static t_gnl			*gnl_init(int const fd, t_gnl **gnl)
{
	t_gnl				*el;

	if ((el = *gnl))
	{
		while (el->prev)
			el = el->prev;
		while (el)
		{
			if (el->fd == fd)
				return (el);
			el = el->next;
		}
	}
	if (!(el = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	el->fd = fd;
	if (!(el->str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	el->prev = NULL;
	el->next = *gnl;
	el->eof = 0;
	el->len = 0;
	if (*gnl != NULL)
		(*gnl)->prev = el;
	return ((*gnl = el));
}

static int				gnl_return(t_gnl **gnl, char **line, char stop)
{
	t_gnl				*old;

	if ((*line = (*gnl)->line))
		return (1);
	free((*gnl)->str);
	if ((*gnl)->prev)
		(*gnl)->prev->next = (*gnl)->next;
	if ((*gnl)->next)
		(*gnl)->next->prev = (*gnl)->prev;
	if ((*gnl)->next == NULL && (*gnl)->prev == NULL)
		ft_memdel((void *)gnl);
	else
	{
		old = *gnl;
		*gnl = ((*gnl)->prev ? (*gnl)->prev : (*gnl)->next);
		ft_memdel((void *)&old);
	}
	*line = NULL;
	return (stop);
}

static void				gnl_getstr(t_gnl *gnl, char *stop)
{
	if (gnl->len > 0 && ((!(gnl->str[0] == '\n') && *stop == 0) || gnl->line))
	{
		gnl->len_old = (gnl->tmp == NULL ? 0 : ft_strlen(gnl->tmp));
		while (gnl->i < gnl->len && gnl->str[gnl->i] != '\n')
			gnl->i++;
		if (gnl->i > 0)
		{
			if (!(gnl->line = ft_strnew(gnl->i + gnl->len_old))
				&& (*stop = -1) == -1)
				return ;
			ft_memmove(gnl->line, gnl->tmp, gnl->len_old);
			ft_memmove(gnl->line + gnl->len_old, gnl->str, gnl->i);
			ft_memdel((void *)&gnl->tmp);
		}
	}
	else if (gnl->len > 0)
		gnl->line = ft_strdup("\0");
	if (gnl->str[gnl->i] == '\n' && (*stop = 1) == *stop)
	{
		gnl->lf = 1;
		ft_memmove(gnl->str, gnl->str + gnl->i + 1, gnl->len - gnl->i);
	}
	else if (gnl->eof == 1)
		ft_memmove(gnl->str, gnl->str + gnl->i, gnl->len - gnl->i);
	ft_memset(gnl->str + gnl->len - gnl->i, '\0', gnl->i);
}

static void				gnl_read(t_gnl *gnl, char *stop)
{
	gnl->len = read(gnl->fd, gnl->str, BUFF_SIZE);
	if (gnl->len == (size_t)(-1) && (*stop = -1) == -1)
		return ;
	gnl->str[gnl->len] = '\0';
	if ((gnl->len != BUFF_SIZE && gnl->fd != 0)
		|| (gnl->fd == 0 && gnl->len == 0))
		gnl->eof = 1;
}

int						get_next_line(int const fd, char **line)
{
	static t_gnl		*gnl = NULL;

	if (!line || fd < 0 || !(gnl = gnl_init(fd, &gnl)))
		return (-1);
	gnl->line = NULL;
	if (gnl->len == 0 && gnl->eof == 1)
		return (gnl_return(&gnl, line, 0));
	gnl->stop = 0;
	gnl->start = 0;
	while (gnl->stop == 0)
	{
		gnl->i = 0;
		gnl->lf = 0;
		gnl->tmp = gnl->line;
		if (gnl->len > 0 || gnl->start == 1)
			gnl_getstr(gnl, &gnl->stop);
		gnl->len -= (gnl->i + gnl->lf);
		if (gnl->eof == 1)
			break ;
		if (gnl->stop == 0 && gnl->eof == 0)
			gnl_read(gnl, &gnl->stop);
		gnl->start = 1;
	}
	return (gnl_return(&gnl, line, gnl->stop));
}
