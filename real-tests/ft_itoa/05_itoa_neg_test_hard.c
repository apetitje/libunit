/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_itoa_neg_test_hard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:04:02 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:26:54 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

int		itoa_neg_test_hard(void)
{
	char	*ret;

	if (!(ret = ft_itoa(-2147483648)))
		return (ST_ERROR);
	ASSERT_STR_EQ(ret, "-2147483648");
	free(ret);
	return (ST_OK);
}
