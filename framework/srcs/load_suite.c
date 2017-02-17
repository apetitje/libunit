/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:37:43 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:17:52 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	init_suite_vars(t_suite_test *new, char *name, t_mode mode,
		t_unit_test *tests)
{
	new->name = ft_strdup(name);
	new->test = tests;
	new->mode = mode;
	new->status = ST_OK;
	new->next = NULL;
}

void		load_suite(t_suite_test **suite, char *name, t_unit_test *tests,
		t_mode mode)
{
	t_suite_test	*new;
	t_suite_test	*ptr;
	t_unit_test		*l_test;

	if (!(new = ft_memalloc(sizeof(t_suite_test))))
		return ;
	init_suite_vars(new, name, mode, tests);
	l_test = tests;
	while (l_test)
	{
		l_test->suite = new->name;
		if (l_test->mode != PENDING)
			l_test->mode = mode;
		l_test = l_test->next;
	}
	if (!*suite)
		*suite = new;
	else
	{
		ptr = *suite;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
