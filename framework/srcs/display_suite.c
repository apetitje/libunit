/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:00:40 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 22:03:03 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	s_display_test_after(t_suite_test_launcher *launcher)
{
	ft_printf("running %zu tests in %f seconds\n", launcher->nb_tests,
			launcher->time_spent);
	ft_printf("success tests: %zu\n", launcher->nb_test_st_ok);
	ft_printf("fail tests: %zu\n", launcher->nb_test_st_fail);
	ft_printf("pending tests: %zu\n", launcher->nb_pending_tests);
	ft_printf("total tests: %zu\n", launcher->nb_tests);
}

void	s_display_test_before(t_suite_test_launcher *launcher)
{
	ft_printf("\033[36m********************************************\033[0m\n");
	ft_printf("\033[36m***               LIBUNIT                ***\033[0m\n");
	ft_printf("\033[36m********************************************\033[0m\n");
	ft_printf("nb suites: %zu\n", launcher->nb_suite);
	ft_printf("nb tests: %zu\n", launcher->nb_tests);
	ft_printf("nb run tests %zu\n", launcher->nb_run_tests);
	ft_printf("nb allow to fail: %zu\n", launcher->nb_allow_to_fail_tests);
}
