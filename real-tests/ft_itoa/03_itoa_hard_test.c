/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_itoa_hard_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:42:20 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:26:29 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

int		itoa_hard_test(void)
{
	char	*ret;

	if (!(ret = ft_itoa(2147483647)))
		return (ST_ERROR);
	ASSERT_STR_EQ(ret, "2147483647");
	free(ret);
	return (ST_OK);
}
