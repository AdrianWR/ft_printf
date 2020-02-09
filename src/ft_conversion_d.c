/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:23:37 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 16:26:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	*ft_length(t_holder *h, va_list args)
{
	intmax_t	d;

	if (h->length & L_CHAR)
		d = (char)(va_arg(args, int));
	else if (h->length & L_SHORT)
		d = (short)(va_arg(args, int));
	else if (h->length & L_LONG)
		d = (long)(va_arg(args, long int));
	else if (h->length & L_LLONG)
		d = (long long)(va_arg(args, long long int));
	else
		d = (int)(va_arg(args, int));
	return ((intmax_t)d);
}

static char	*ft_precision(intmax_t d, t_holder *h)
{
	char	*src;
	char	*dest;

	if (d < 0)
	{
		src = ft_uitoa_base((uintmax_t)-d, DEC_BASE);
		dest = ft_strjoin("-", (ft_pad_left(src, '0', h->precision)));
	}
	else
	{
		if (d == 0 && !h->precision)
			src = ft_strdup(STR_EMPTY);
		else
			src = ft_uitoa_base(d, DEC_BASE);
		if (h->flags & FLAG_PLUS)
			dest = ft_strjoin(PLUS, (ft_pad_left(src, ZERO, h->precision)));
		else if (h->flags & FLAG_SPACE)
dd
			dest = ft_strjoin(SPACE, (ft_pad_left(src, ZERO, h->precision)));
		else
			dest = ft_pad_left(src, '0', h->precision);
	}
	return (dest);
}

static char	*ft_width(char *src, t_holder *h)
{
	char	pad;
	char	*dest;

	pad = SPACE;
	if (h->width <= (int)ft_strlen(src))
		return (ft_strdup(src));
	else
	{
		if (h->flags & FLAG_MINUS)
			dest = ft_pad_right(src, pad, h->width);
		else
		{
			if ((h->flags & FLAG_ZERO) && h->precision < 0)
				pad = ZERO;
			dest = ft_pad_left(src, pad, h->width);
		}
		if (ft_strchr(SIGNALS, src[0]) && pad == ZERO)
		{
			dest[0] = *ft_strchr(SIGNALS, src[0]);
			dest[h->width - ft_strlen(src)] = pad;
		}
	}
	return (dest);
}

char		*ft_conversion_d(t_holder *h, va_list args)
{
	intmax_t	d;
	char		*replace;
	char		*tmp;

	d = ft_length(h, args);
	tmp = ft_precision(d, h);
	replace = ft_width(tmp, h);
	free(tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
