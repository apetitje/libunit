/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_putstr_hard_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:02:09 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:07:25 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr_test.h"

int		putstr_hard_test(void)
{
	ASSERT_STR_STDOUT(&ft_putstr,
			" J\te suis un\ne p'hras***^^^@e '\v]ch Bin D'euts}}che");
	return (ST_OK);
}
