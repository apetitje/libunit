/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_strtolower_medium_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:16:05 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 16:17:18 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strtolower_test.h"

int		strtolower_medium_test(void)
{
	char	*str;

	if (!(str = ft_strdup("SaLuT Je sUIs UNE PhRAse")))
		return (-2);
	ASSERT_STR_EQ(ft_strtolower(str), "salut je suis une phrase");
	free(str);
	return (ST_OK);
}
