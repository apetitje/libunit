/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_assert_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:27:13 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 20:29:51 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	assert_lt(int x, int y, char *s, int l)
{
	if (x < y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d < %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	assert_le(int x, int y, char *s, int l)
{
	if (x <= y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d <= %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	assert_gt(int x, int y, char *s, int l)
{
	if (x > y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d > %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	assert_ge(int x, int y, char *s, int l)
{
	if (x >= y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d >= %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}
