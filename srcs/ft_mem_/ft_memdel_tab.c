/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_tab(void ***ap)
{
	size_t	i;

	if (*ap != NULL)
	{
		i = 0;
		while ((*ap)[i])
		{
			ft_memdel((void **)&(*ap)[i]);
			i++;
		}
		ft_memdel((void **)&(*ap));
		*ap = NULL;
	}
}
