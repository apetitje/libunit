/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tests_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:21:57 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 20:55:46 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	free_test_suite(t_suite_test **list)
{
	t_suite_test	*ptr;
	t_suite_test	*tmp;
	t_unit_test		*unit_tmp;

	ptr = *list;
	while (ptr)
	{
		free(ptr->name);
		while (ptr->test)
		{
			free(ptr->test->name);
			unit_tmp = ptr->test;
			ptr->test = ptr->test->next;
			free(unit_tmp);
		}
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	*list = NULL;
}
