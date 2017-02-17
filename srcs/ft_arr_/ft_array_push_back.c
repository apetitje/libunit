/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function duplicates the value `*value` and push it at the end
** of the array pointed by `***array` through an allocation of a new one.
** If either parameter is NULL, it returns -1.
** If the array pointed by `***array` is NULL, a new one is created.
** On failure, the function returns -1 and `***array` is not changed.
** On success, the function returns the new size of the array.
*/

int			ft_array_push_back(char ***array, char const *value)
{
	size_t	total;

	if (!value || !array)
		return (-1);
	total = 0;
	if (*array)
		while ((*array)[total])
			total++;
	return (ft_array_push_index(array, value, total));
}
