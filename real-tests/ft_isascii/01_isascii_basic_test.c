/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_isascii_basic_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:06:11 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 21:06:12 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isascii_test.h"

int		isascii_basic_test(void)
{
	ASSERT_TRUE(ft_isascii(42));
	return (ST_OK);
}
