/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_segv_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:05:52 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:23:46 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int		segv_test(void)
{
	char	*src;

	src = NULL;
	ASSERT_STR_EQ(*(func_to_test(&src)), "11111111");
	return (ST_OK);
}
