/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:23:37 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 21:49:17 by aroque           ###   ########.fr       */
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

static void		ft_precision(intmax_t d, t_holder *h)
{
	if (h->flags & FLAG_SPACE)
		h->prefix = ' ';
	if (h->flags & FLAG_PLUS)
		h->prefix = '+';
	if (d == 0 && !h->precision)
		h->replace = ft_strdup(STR_EMPTY);
	else
	{
		if (d < 0)
		{
			h->prefix = MINUS;
			d = (uintmax_t)(d * -1);
		}
		h->replace = ft_uitoa_base(d, DEC_BASE);
	}
	ft_pad_left(&h->replace, '0', h->precision);
	h->prefix ? h->width-- : h->width;
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, ' ', h->width);
	else if ((h->flags & FLAG_ZERO) && h->precision < 0)
		ft_pad_left(&h->replace, '0', h->width);
	ft_prefix(h);
	h->prefix ? h->width++ : h->width;
	ft_pad_left(&h->replace, ' ', h->width);
}

void			ft_conversion_d(t_holder *h, va_list args)
{
	intmax_t	d;

	d = ft_length(h, args);
	ft_precision(d, h);
	h->len = ft_strlen(h->replace);
}
