/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_buse_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:08:36 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:23:51 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int		buse_test(void)
{
	char	*src;

	src = "abcdefgh";
	ASSERT_STR_EQ(*(func_to_test(&src)), "11111111");
	return (ST_OK);
}
