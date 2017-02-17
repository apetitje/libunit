/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <anouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by anouvel           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft.h"

static void			ft_wctomb_32(char **dest, wchar_t *c, short *len)
{
	(*dest)[(*len)] = (char)((*c >> 18) | 0xF0);
	(*dest)[(*len)] = (char)(((*c >> 12) & 0x3F) | 0x80);
	(*dest)[(*len)] = (char)(((*c >> 6) & 0x3F) | 0x80);
	(*dest)[(*len)] = (char)((*c & 0x3F) | 0x80);
}

static void			ft_wctomb_16(char **dest, wchar_t *c, short *len)
{
	(*dest)[(*len)++] = (char)((*c >> 12) | 0xE0);
	(*dest)[(*len)++] = (char)(((*c >> 6) & 0x3F) | 0x80);
	(*dest)[(*len)++] = (char)((*c & 0x3F) | 0x80);
}

static void			ft_wctomb_12(char **dest, wchar_t *c, short *len)
{
	(*dest)[(*len)++] = (char)((*c >> 6) | 0xC0);
	(*dest)[(*len)++] = (char)((*c & 0x3F) | 0x80);
}

static void			ft_wctomb_8(char **dest, wchar_t *c, short *len)
{
	(*dest)[(*len)++] = (char)(*c);
}

short				ft_wctomb(char *dest, wchar_t c)
{
	short			len;

	len = 0;
	if (dest == NULL)
		return (0);
	if (c < (1 << 7))
		ft_wctomb_8(&dest, &c, &len);
	else if (c < (1 << 11))
		ft_wctomb_12(&dest, &c, &len);
	else if (c < (1 << 16))
		ft_wctomb_16(&dest, &c, &len);
	else if (c < (1 << 21))
		ft_wctomb_32(&dest, &c, &len);
	else
		return (-1);
	dest[len] = '\0';
	return (len);
}
