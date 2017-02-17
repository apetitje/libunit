/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_putstr_empty_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:03:25 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 17:14:31 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr_test.h"

int		putstr_empty_test(void)
{
	ASSERT_STR_STDOUT(&ft_putstr, "");
	return (ST_OK);
}
