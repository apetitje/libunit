/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_isascii_false_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:10:19 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:33:49 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isascii_test.h"

int		isascii_false_test(void)
{
	ASSERT_FALSE(ft_isascii(512));
	return (ST_OK);
}
