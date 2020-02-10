/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:23:37 by aroque            #+#    #+#             */
/*   Updated: 2020/02/10 15:45:02 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	ft_length(t_holder *h, va_list args)
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

static void	ft_precision(intmax_t d, t_holder *h)
{
	int		len;

	len = h->precision;
	if (d < 0)
	{
		h->prefix = '-';
		h->replace = ft_uitoa_base((uintmax_t)-d, DEC_BASE);
		ft_pad_left(h->replace, '0', len);
	}
	else
	{
		if (d == 0 && !h->precision)
			h->replace = ft_strdup(STR_EMPTY);
		else
			h->replace = ft_uitoa_base(d, DEC_BASE);
		if (h->flags & FLAG_PLUS)
			ft_pad_left(h->replace, '0', len);
		else if (h->flags & FLAG_SPACE)
			ft_pad_left(h->replace, '0', len);
		else
			ft_pad_left(h->replace, '0', len);
	}
}

static void	ft_width(t_holder *h)
{
	char	pad;
	//char	*dest;

	pad = ' ';
	{
		//if (h->flags & FLAG_MINUS)
		//	ft_pad_right(src, pad, h->width);
		//else
		{
			if ((h->flags & FLAG_ZERO) && h->precision < 0)
				pad = '0';
			ft_pad_left(h->replace, pad, h->width);
		}
		//if (ft_strchr(SIGNALS, src[0]) && pad == '0')
		//{
		//	dest[0] = *ft_strchr(SIGNALS, src[0]);
		//	dest[h->width - ft_strlen(src)] = pad;
		//}
	}
}

char		*ft_conversion_d(t_holder *h, va_list args)
{
	intmax_t	d;

	d = ft_length(h, args);
	ft_precision(d, h);
	ft_width(h);
	ft_prefix(h);
	h->len = ft_strlen(h->replace);
	return (h->replace);
}
