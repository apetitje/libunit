/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions may duplicate `**array`, or return NULL
*/

char	**ft_array_dup(char **array)
{
	size_t	size;
	char	**new_array;

	size = 0;
	while (array[size])
		size++;
	if ((new_array = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	size = 0;
	while (array[size])
	{
		if ((new_array[size] = ft_strdup(array[size])) == NULL)
			return (NULL);
		size++;
	}
	new_array[size] = NULL;
	return (new_array);
}
