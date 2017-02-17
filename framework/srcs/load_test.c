/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:28:04 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 20:23:06 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **test_list, char *name, int (*f)(void),
		t_mode mode)
{
	t_unit_test	*new;
	t_unit_test	*ptr;

	if (!(new = ft_memalloc(sizeof(t_unit_test))))
		return ;
	new->next = NULL;
	new->name = ft_strdup(name);
	new->func = f;
	new->signal = 0;
	new->status = ST_OK;
	new->mode = mode;
	if (!*test_list)
		*test_list = new;
	else
	{
		ptr = *test_list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
