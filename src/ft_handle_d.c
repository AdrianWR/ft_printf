/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:23:37 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:57:41 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static char	*ft_handle_precision(int d, t_holder *h)
{
	char	*src;
	char	*dest;

	if (d == 0 && h->precision == 0)
		dest = ft_strdup(STR_EMPTY);
	else if (d < 0)
	{
		src = ft_itoa_ubase((unsigned)-d, DEC_BASE);
		dest = ft_strjoin("-", (ft_pad_left(src, '0', h->precision)));
		free(src);
	}
	else
		dest = ft_pad_left(ft_itoa_ubase(d, DEC_BASE), '0', h->precision);
	return (dest);
}

static char	*ft_handle_width(char *src, t_holder *h)
{
	char	pad;
	char	*dest;

	pad = ' ';
	if (h->width <= (int)ft_strlen(src))
		return (ft_strdup(src));
	else
	{
		if (h->flags & FLAG_MINUS)
			dest = ft_pad_right(src, pad, h->width);
		else
		{
			if ((h->flags & FLAG_ZERO) && h->precision < 0)
				pad = '0';
			dest = ft_pad_left(src, pad, h->width);
		}
		if (src[0] == '-' && pad == '0')
		{
			dest[0] = '-';
			dest[h->width - ft_strlen(src)] = pad;
		}
	}
	return (dest);
}

char		*ft_handle_d(t_holder *h, va_list args)
{
	char	*replace;
	char	*tmp;

	tmp = ft_handle_precision(va_arg(args, int), h);
	replace = ft_handle_width(tmp, h);
	free(tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
