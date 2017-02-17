/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test_get_return.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:17:20 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 21:32:06 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_status	s_unit_test_get_return_signal(t_suite_test_launcher *launcher,
		t_unit_test *test)
{
	test->status = ST_FAIL;
	launcher->nb_test_st_fail++;
	if (WTERMSIG(test->term) == SIGSEGV)
	{
		test->signal = SIGSEGV;
		ft_printf("\t\033[33m[SEGV]\033[0m\n");
		return (ST_FAIL);
	}
	else if (WTERMSIG(test->term) == SIGBUS)
	{
		test->signal = SIGBUS;
		ft_printf("\t\033[33m[BUSE]\033[0m\n");
		return (ST_FAIL);
	}
	else if (WTERMSIG(test->term) == SIGUSR1)
	{
		test->signal = SIGUSR1;
		ft_printf("\t\033[33m[TIMEOUT]\033[0m\n");
		return (ST_FAIL);
	}
	else
	{
		return (ST_FAIL);
	}
}

t_status	s_unit_test_get_return_value(t_suite_test_launcher *launcher,
		t_unit_test *test)
{
	if (WEXITSTATUS(test->term) == 0 || test->mode == ALLOW_TO_FAIL)
	{
		ft_printf("\t\033[32m[OK] (%f sec)\033[0m\n", test->time_spent * 1000);
		test->status = ST_OK;
		launcher->nb_test_st_ok++;
		return (ST_OK);
	}
	else
	{
		ft_printf("\t\033[31m[KO] (%f sec)\033[0m\n", test->time_spent * 1000);
		test->status = ST_FAIL;
		launcher->nb_test_st_fail++;
		return (ST_FAIL);
	}
}
