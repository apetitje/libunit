/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_indexof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions may iterate on `**array` and compare each element to
** the string `*str` with the function `ft_strcmp`.
** It returns `1` on success and `0` on missing element.
*/

int	ft_array_indexof(char const **array, char const *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp(array[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}
