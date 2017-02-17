/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_itoa_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:39:52 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:32:32 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

t_unit_test	*ft_itoa_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &itoa_basic_test, RUN);
	load_test(&test_list, "Medium test", &itoa_medium_test, RUN);
	load_test(&test_list, "Hard test", &itoa_hard_test, RUN);
	load_test(&test_list, "Neg test", &itoa_neg_test, RUN);
	load_test(&test_list, "Hard neg test", &itoa_neg_test_hard, RUN);
	return (test_list);
}
