/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:36:46 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 19:30:09 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_TEST_H
# define FT_ITOA_TEST_H

# include "libunit.h"
# include "libft.h"

t_unit_test	*ft_itoa_launcher(void);
int			itoa_basic_test(void);
int			itoa_medium_test(void);
int			itoa_hard_test(void);
int			itoa_neg_test(void);
int			itoa_neg_test_hard(void);
int			test_str(void);

#endif
