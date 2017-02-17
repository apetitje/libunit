/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:28:59 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:03:38 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi_test.h"
#include "libunit.h"

t_unit_test		*atoi_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &basic_test, RUN);
	load_test(&test_list, "Hard test", &hard_test, RUN);
	return (test_list);
}
