/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_itoa_neg_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:45:03 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:26:41 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

int		itoa_neg_test(void)
{
	char	*ret;

	if (!(ret = ft_itoa(-12456)))
		return (ST_ERROR);
	ASSERT_STR_EQ(ret, "-12456");
	free(ret);
	return (ST_OK);
}
