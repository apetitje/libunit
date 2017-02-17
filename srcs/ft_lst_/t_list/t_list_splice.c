/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_splice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	t_list_splice(t_list *list, t_list *head)
{
	t_list	*first;
	t_list	*last;
	t_list	*at;

	first = list->next;
	last = list->prev;
	at = head->next;
	first->prev = head;
	head->next = first;
	last->next = at;
	at->prev = last;
}
