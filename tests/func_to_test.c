/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_to_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:50:16 by apetitje          #+#    #+#             */
/*   Updated: 2017/02/12 14:53:54 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**func_to_test(char **src)
{
	int		i;

	i = -1;
	while ((*src)[++i])
		(*src)[i] = '1';
	return (src);
}
