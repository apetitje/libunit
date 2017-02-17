/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_putstr_basic_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:44:44 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 17:14:51 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr_test.h"

int		putstr_basic_test(void)
{
	ASSERT_STR_STDOUT(&ft_putstr, "je suis une phrase");
	return (ST_OK);
}
