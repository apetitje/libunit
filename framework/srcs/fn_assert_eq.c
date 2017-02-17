/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_assert_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:29:21 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 20:29:37 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	assert_eq(int x, int y, char *s, int l)
{
	if (x != y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d == %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	assert_ne(int x, int y, char *s, int l)
{
	if (x == y)
	{
		ft_printf("[ ASSERT ] %s (%d): expected %d != %d\n", s, l, x, y);
		return (-1);
	}
	else
	{
		return (0);
	}
}
