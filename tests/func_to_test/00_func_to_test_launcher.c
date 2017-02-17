/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_func_to_test_launcher.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:55:46 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:45:27 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

t_unit_test		*func_to_test_launcher(void)
{
	t_unit_test *test_list;

	test_list = NULL;
	load_test(&test_list, "OK test", &ok_test, RUN);
	load_test(&test_list, "KO test", &ko_test, RUN);
	load_test(&test_list, "SEGV test", &segv_test, RUN);
	load_test(&test_list, "BUSE test", &buse_test, RUN);
	load_test(&test_list, "TIMEOUT test", &timeout_test, RUN);
	return (test_list);
}
