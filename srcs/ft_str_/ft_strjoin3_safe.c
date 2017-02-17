/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3_safe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin3_safe(char const *s1, char const *s2,
		char const *s3)
{
	char		*new;
	size_t		len;
	size_t		i;

	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (s3)
		len += ft_strlen(s3);
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	len = -1;
	if (s1 && (i = -1))
		while (s1[++i])
			new[++len] = s1[i];
	if (s2 && (i = -1))
		while (s2[++i])
			new[++len] = s2[i];
	if (s3 && (i = -1))
		while (s3[++i])
			new[++len] = s3[i];
	return (new);
}
