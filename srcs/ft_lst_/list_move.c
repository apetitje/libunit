/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_move(t_list *list, t_list *head)
{
	t_list_del(list->prev, list->next);
	list_push_front(list, head);
}

void	list_move_tail(t_list *list, t_list *head)
{
	t_list_del(list->prev, list->next);
	list_push_back(list, head);
}
