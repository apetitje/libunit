/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:05:08 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 21:50:07 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <time.h>

pid_t			g_test_pid = 0;

static t_status	s_exec_unit_test_child(t_suite_test_launcher *launcher,
		t_unit_test *test)
{
	clock_t	begin;
	clock_t	end;

	ft_printf("\033[36m[ %s ]\033[32m[ RUN ] \033[0m- %s\n", test->suite,
			test->name);
	begin = clock();
	alarm(TIMEOUT);
	if (wait(&test->term) == -1)
	{
		return (ST_ERROR);
	}
	end = clock();
	test->time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	if (WIFEXITED(test->term))
	{
		return (s_unit_test_get_return_value(launcher, test));
	}
	else if (WIFSIGNALED(test->term))
	{
		return (s_unit_test_get_return_signal(launcher, test));
	}
	else
	{
		return (ST_ERROR);
	}
}

static int		s_fork_pid(pid_t *pid)
{
	if ((*pid = fork()) == -1)
	{
		return (ST_ERROR);
	}
	else
	{
		return (ST_OK);
	}
}

static int		s_exec_unit_test(t_suite_test_launcher *launcher,
		t_unit_test *test)
{
	t_status	st;
	pid_t		pid;

	if ((st = s_fork_pid(&pid)) != ST_OK)
	{
		return (st);
	}
	if (pid > 0)
	{
		g_test_pid = pid;
		st = s_exec_unit_test_child(launcher, test);
	}
	else if (pid == 0)
	{
		st = test->func();
		exit(st);
	}
	return (st);
}

void			handler(int sig)
{
	signal(SIGALRM, SIG_IGN);
	if (sig == SIGALRM)
	{
		kill(g_test_pid, SIGUSR1);
	}
	signal(SIGALRM, handler);
}

int				launch_tests(t_suite_test_launcher *launcher,
		t_unit_test **test_list)
{
	t_unit_test	*ptr;
	t_status	st;

	signal(SIGALRM, handler);
	ptr = *test_list;
	while (ptr)
	{
		if (ptr->mode != PENDING)
			st = s_exec_unit_test(launcher, ptr);
		ptr = ptr->next;
	}
	return (st);
}
