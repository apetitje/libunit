/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:04:55 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 22:02:01 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_test.h"
#include "ft_itoa_test.h"
#include "ft_strtolower_test.h"
#include "isascii_test.h"
#include "putstr_test.h"

int		main(void)
{
	t_suite_test	*suite;

	suite = NULL;
	load_suite(&suite, "ft_strtolower", ft_strtolower_launcher(), RUN);
	load_suite(&suite, "ft_atoi", atoi_launcher(), RUN);
	load_suite(&suite, "ft_itoa", ft_itoa_launcher(), RUN);
	load_suite(&suite, "ft_isascii", ft_isascii_launcher(), RUN);
	load_suite(&suite, "ft_putstr", putstr_launcher(), RUN);
	return (launch_suite(&suite));
}
