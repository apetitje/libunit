/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:04:43 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 21:04:44 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	assert_true(int boolean, char *s, int l)
{
	if (!boolean)
	{
		ft_printf("[ ASSERT ] %s (%d): expected TRUE - got FALSE\n", s, l);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	assert_false(int boolean, char *s, int l)
{
	if (boolean)
	{
		ft_printf("[ ASSERT ] %s (%d): expected FALSE - got TRUE\n", s, l);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	astreq(const char *x, const char *y, char *s, int l)
{
	if (ft_strcmp(x, y) != 0)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %s == %s\n", s, l, x, y);
		return (-1);
	}
	{
		return (0);
	}
}

int	astrne(const char *x, const char *y, char *s, int l)
{
	if (ft_strcmp(x, y) == 0)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %s != %s\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	aout(void (*f)(const char *), char *cmp, char *s, int l)
{
	int		pipe_fds[2];
	int		stdin_save;
	int		stdout_save;
	char	str[256];

	pipe(pipe_fds);
	stdin_save = dup(STDIN_FILENO);
	stdout_save = dup(STDOUT_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	f(cmp);
	close(pipe_fds[1]);
	dup2(stdout_save, STDOUT_FILENO);
	dup2(pipe_fds[0], STDIN_FILENO);
	ft_bzero(str, 256);
	read(STDIN_FILENO, str, 256);
	close(pipe_fds[0]);
	dup2(stdin_save, STDIN_FILENO);
	return (astreq(cmp, str, s, l));
}
