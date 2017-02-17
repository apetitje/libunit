/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_itoa_medium_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:41:37 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:27:14 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_itoa_test.h"

int		itoa_medium_test(void)
{
	char	*ret;

	if (!(ret = ft_itoa(123456789)))
		return (ST_ERROR);
	ASSERT_STR_EQ(ret, "123456789");
	free(ret);
	return (ST_OK);
}
