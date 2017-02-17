/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ko_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:02:17 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:23:11 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int	ko_test(void)
{
	char	*src;

	if (!(src = ft_strdup("abcdefgh")))
		return (ST_ERROR);
	ASSERT_STR_EQ(*(func_to_test(&src)), "22222222");
	free(src);
	return (ST_OK);
}
