/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function duplicates the value `*value` and push it at position `index`
** of the array pointed by `***array` through an allocation of a new one.
** If either parameter is NULL, it returns -1.
** If the array pointed by `***array` is NULL, a new one is created.
** On failure, the function returns -1 and `***array` is not changed.
** On success, the function returns the new size of the array.
*/

static void	s_iterate_on_array(char **array, char ***new_array,
						size_t index)
{
	size_t	i;
	int		total;

	i = 0;
	total = 0;
	while (array[i])
	{
		if (i == index)
			(*new_array)[total++] = NULL;
		(*new_array)[total++] = array[i];
		i++;
	}
}

int			ft_array_push_index(char ***array, char const *value,
				size_t index)
{
	char	**new_array;
	size_t	total;

	if (!value || !array)
		return (-1);
	total = 0;
	while (*array && (*array)[total])
		total++;
	if (index > total)
		index = total;
	if ((new_array = (char **)malloc(sizeof(char *) * (total + 2))) == NULL)
		return (-1);
	if (*array && total > 0)
		s_iterate_on_array(*array, &new_array, index);
	total++;
	if ((new_array[index] = ft_strdup(value)) == NULL)
		return (-1);
	new_array[total] = NULL;
	free(*array);
	*array = new_array;
	return (total);
}
