/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_suite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:54:50 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:33:43 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int						get_suite_rslt(t_suite_test_launcher *launcher,
		t_status st)
{
	if (st == ST_ERROR)
		return (-2);
	if (launcher->nb_test_st_fail != 0)
		return (-1);
	return (0);
}

/*
** Runs the test suite
*/

static t_status					run_test_suite(t_suite_test_launcher *launcher,
		t_suite_test **suite)
{
	t_suite_test				*ptr;
	clock_t						begin;
	clock_t						end;

	ptr = *suite;
	while (ptr)
	{
		if (ptr->mode != PENDING)
		{
			begin = clock();
			launch_tests(launcher, &(ptr->test));
			end = clock();
			ptr->time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			launcher->time_spent += ptr->time_spent;
		}
		ptr = ptr->next;
	}
	return (ST_OK);
}

/*
** Counts the types of tests of the test suite and fill the wrapper structure
*/

static void						suite_cnt_tests(t_suite_test_launcher *launcher,
		t_suite_test *suite)
{
	t_unit_test					*ptr;

	ptr = suite->test;
	while (ptr)
	{
		launcher->nb_tests++;
		if (ptr->mode == RUN)
			launcher->nb_run_tests++;
		else if (ptr->mode == ALLOW_TO_FAIL)
			launcher->nb_allow_to_fail_tests++;
		else if (ptr->mode == PENDING)
			launcher->nb_pending_tests++;
		ptr = ptr->next;
	}
}

/*
** Creates a test suite wrapper to store test variables
*/

static t_suite_test_launcher	*s_suite_launcher_init(t_suite_test **suite)
{
	t_suite_test_launcher		*suite_launcher;
	t_suite_test				*ptr;

	if (!(suite_launcher = ft_memalloc(sizeof(t_suite_test_launcher))))
		return (NULL);
	ptr = *suite;
	while (ptr)
	{
		suite_launcher->nb_suite++;
		suite_cnt_tests(suite_launcher, ptr);
		ptr = ptr->next;
	}
	return (suite_launcher);
}

/*
** Runs the tests suite.
** Returns 0 (ST_OK) on success
** -1 on test failure
** -2 on framework error
*/

int								launch_suite(t_suite_test **suite)
{
	t_status					st;
	t_suite_test_launcher		*suite_launcher;

	if (!(suite_launcher = s_suite_launcher_init(suite)))
		return (-1);
	s_display_test_before(suite_launcher);
	st = run_test_suite(suite_launcher, suite);
	s_display_test_after(suite_launcher);
	free_test_suite(suite);
	return (get_suite_rslt(suite_launcher, st));
}
