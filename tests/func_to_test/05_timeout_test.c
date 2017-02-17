/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_timeout_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:18:48 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:07:34 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int	timeout_test(void)
{
	char	*src;

	if (!(src = ft_strdup("abcdefgh")))
		return (ST_ERROR);
	ASSERT_STR_EQ(*(func_to_test(&src)), "11111111");
	free(src);
	while (1)
	{
	}
	return (ST_OK);
}
