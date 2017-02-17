/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Display an int in the standard out file descriptor.
** @param	n		the int to print
*/

void		ft_putnbr(int n)
{
	char c;

	c = '0';
	if (n < 0)
	{
		ft_putchar('-');
		c -= (n % 10);
		if (n < -9)
			ft_putnbr(-(n / 10));
		ft_putchar(c);
	}
	if (n > 0)
	{
		c += n % 10;
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(c);
	}
	else if (n == 0)
		ft_putchar(c);
}
