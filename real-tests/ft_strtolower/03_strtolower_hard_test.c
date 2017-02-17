/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strtolower_hard_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:41:48 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:17:25 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strtolower_test.h"

int		strtolower_hard_test(void)
{
	char	*str;

	if (!(str = ft_strdup("S4aL5uT 00Je sUIs UNE ]PhRAse///8")))
		return (-2);
	ASSERT_STR_EQ(ft_strtolower(str), "s4al5ut 00je suis une ]phrase///8");
	free(str);
	return (ST_OK);
}
