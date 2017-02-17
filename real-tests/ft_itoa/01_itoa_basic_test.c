/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_itoa_basic_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:40:30 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:36:25 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

int		itoa_basic_test(void)
{
	char	*ret;

	if (!(ret = ft_itoa(0)))
		return (ST_ERROR);
	ASSERT_STR_EQ(ret, "0");
	free(ret);
	return (ST_OK);
}
