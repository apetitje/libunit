/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isascii_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:18:39 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:34:10 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isascii_test.h"
#include "libunit.h"

t_unit_test		*ft_isascii_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &isascii_basic_test, RUN);
	load_test(&test_list, "False test", &isascii_false_test, RUN);
	return (test_list);
}
