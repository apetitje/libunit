/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_putstr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:56:14 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:31:28 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putstr_test.h"
#include "libunit.h"

t_unit_test		*putstr_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &putstr_basic_test, RUN);
	load_test(&test_list, "Medium test", &putstr_medium_test, RUN);
	load_test(&test_list, "Hard test", &putstr_hard_test, RUN);
	load_test(&test_list, "Empty test", &putstr_empty_test, RUN);
	return (test_list);
}
