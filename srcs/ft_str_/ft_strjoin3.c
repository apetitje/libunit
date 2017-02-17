/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char		*new;
	size_t		len;
	size_t		i;

	if (s1 && s2 && s3)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
		if (new)
		{
			len = -1;
			i = -1;
			while (s1[++i])
				new[++len] = s1[i];
			i = -1;
			while (s2[++i])
				new[++len] = s2[i];
			i = -1;
			while (s3[++i])
				new[++len] = s3[i];
			return (new);
		}
	}
	return (NULL);
}
