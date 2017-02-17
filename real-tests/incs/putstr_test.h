/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:09:00 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:12:49 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTSTR_TEST_H
# define FT_PUTSTR_TEST_H

# include "libunit.h"
# include "libft.h"

t_unit_test	*putstr_launcher(void);
int			putstr_basic_test(void);
int			putstr_medium_test(void);
int			putstr_hard_test(void);
int			putstr_empty_test(void);

#endif
