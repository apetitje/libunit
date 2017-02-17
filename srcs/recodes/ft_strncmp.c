/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	cmp = 0;
	if (s1 && s2)
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && i < n && cmp == 0)
		{
			cmp = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
			i++;
		}
	}
	return (cmp);
}
