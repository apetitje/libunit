/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumeric(char const *str)
{
	char const	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (str == ptr)
		{
			if (ft_isdigit(*ptr) == 0 && *ptr != '-' && *ptr != '+')
				return (0);
		}
		else if (ft_isdigit(*ptr) == 0)
			return (0);
		ptr++;
	}
	return (1);
}
