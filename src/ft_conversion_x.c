/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:20:42 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 14:21:12 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision(unsigned int u, t_holder *h, char *base)
{
	char *tmp;
	char hash_start[2];

	hash_start[0] = '0';
	hash_start[1] = h->conversion;
	if (u == 0 && h->precision == 0)
		tmp = (ft_strdup(STR_EMPTY));
	else
		tmp = ft_pad_left(ft_uitoa_base(u, base), '0', h->precision);
	if (u > 0 && h->conversion != 'u' && h->flags & FLAG_HASH)
		return (ft_strjoin(hash_start, tmp));
	return (tmp);
}

static char	*ft_width(char *src, t_holder *h)
{
	char	pad;
	char	*dest;

	pad = ' ';
	if (h->width <= (int)ft_strlen(src))
		return (ft_strdup(src));
	if (h->flags & FLAG_MINUS)
		dest = ft_pad_right(src, pad, h->width);
	else
	{
		if ((h->flags & FLAG_ZERO) && h->precision < 0)
			pad = '0';
		dest = ft_pad_left(src, pad, h->width);
	}
	return (dest);
}

char		*ft_conversion_x(t_holder *h, va_list args, char *base)
{
	char	*replace;
	char	*tmp;

	tmp = ft_precision(va_arg(args, unsigned int), h, base);
	replace = ft_width(tmp, h);
	free(tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
