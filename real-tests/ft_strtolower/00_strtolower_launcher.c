/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strtolower_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:44:47 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 22:02:01 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtolower_test.h"
#include "libunit.h"

t_unit_test	*ft_strtolower_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &strtolower_basic_test, RUN);
	load_test(&test_list, "Medium test", &strtolower_medium_test, RUN);
	load_test(&test_list, "Hard test", &strtolower_hard_test, RUN);
	return (test_list);
}
