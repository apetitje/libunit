/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ok_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:49:25 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:49:26 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int	ok_test(void)
{
	char	*src;

	if (!(src = ft_strdup("abcdefgh")))
		return (ST_ERROR);
	ASSERT_STR_EQ(*(func_to_test(&src)), "11111111");
	free(src);
	return (ST_OK);
}
