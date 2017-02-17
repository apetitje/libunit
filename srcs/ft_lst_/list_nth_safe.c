/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_nth_safe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
** This function is similar to `list_nth` except that it iterates
** on elements once only, it may return NULL when index
** is not found.
*/

t_list	*list_nth_safe(const t_list *head, const int index)
{
	t_list		*tmp;
	int			i;

	tmp = (t_list *)head;
	i = 0;
	if (index > 0)
	{
		while (i < index)
		{
			tmp = tmp->next;
			if (tmp == head)
				return (NULL);
			i++;
		}
		return (tmp);
	}
	while (i > index)
	{
		tmp = tmp->prev;
		if (tmp == head)
			return (NULL);
		i--;
	}
	return (tmp);
}
