/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower_test.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:57:38 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:12:40 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOLOWER_TEST_H
# define FT_STRTOLOWER_TEST_H

# include "libunit.h"
# include "libft.h"

t_unit_test *ft_strtolower_launcher(void);
int			strtolower_basic_test(void);
int			strtolower_medium_test(void);
int			strtolower_hard_test(void);

#endif
