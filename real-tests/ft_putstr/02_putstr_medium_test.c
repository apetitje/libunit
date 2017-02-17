/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_putstr_medium_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:01:54 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:33:33 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr_test.h"

int		putstr_medium_test(void)
{
	ASSERT_STR_STDOUT(&ft_putstr, " C'est phrase 0123456;Ich Bin Deutsche");
	return (ST_OK);
}
