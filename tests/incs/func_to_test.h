/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_to_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:54:37 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:18:56 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_TO_TEST_H
# define FUNC_TO_TEST_H

# include "libunit.h"

char		**func_to_test(char **src);
t_unit_test	*func_to_test_launcher(void);
int			ok_test(void);
int			ko_test(void);
int			segv_test(void);
int			buse_test(void);
int			timeout_test(void);

#endif
