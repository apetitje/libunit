/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:52:07 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 21:21:13 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_to_test.h"
#include "libunit.h"

int		main(void)
{
	t_suite_test	*suite;

	suite = NULL;
	load_suite(&suite, "func_to_test", func_to_test_launcher(), RUN);
	return (launch_suite(&suite));
}
