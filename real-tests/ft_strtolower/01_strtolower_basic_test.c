/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_strtolower_basic_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:06:38 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:31:13 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strtolower_test.h"

int		strtolower_basic_test(void)
{
	char	*str;

	if (!(str = ft_strdup("SALUT JE SUIS UNE PHRASE")))
		return (-2);
	ASSERT_STR_EQ(ft_strtolower(str), "salut je suis une phrase");
	free(str);
	return (ST_OK);
}
