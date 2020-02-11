/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:29:59 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 12:28:54 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static uintmax_t	ft_length(t_holder *h, va_list args)
{
	uintmax_t	u;

	if (h->length & L_CHAR)
		u = (unsigned char)(va_arg(args, unsigned int));
	else if (h->length & L_SHORT)
		u = (unsigned short)(va_arg(args, unsigned int));
	else if (h->length & L_LONG)
		u = (unsigned long)(va_arg(args, unsigned long int));
	else if (h->length & L_LLONG)
		u = (unsigned long long)(va_arg(args, unsigned long long int));
	else
		u = (unsigned int)(va_arg(args, unsigned int));
	return ((uintmax_t)u);
}

static void	ft_alternate(t_holder *h)
{
	int len;

	len = (int)ft_strlen(h->replace);
	if (h->flags & FLAG_HASH)
	{
		if (h->conversion == 'x' || h->conversion == 'X')
			ft_pad_left(&h->replace, h->conversion, ++len);
		ft_pad_left(&h->replace, ZERO, ++len);
	}
}

static void	ft_precision(uintmax_t u, t_holder *h, const char *base)
{
	if (h->flags & FLAG_SPACE)
		h->prefix = ' ';
	if (h->flags & FLAG_PLUS)
		h->prefix = '+';
	if (u == 0 && !h->precision)
		h->replace = ft_strdup(STR_EMPTY);
	else
		h->replace = ft_uitoa_base(u, base);
	ft_pad_left(&h->replace, '0', h->precision);
	ft_alternate(h);
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, ' ', h->width);
	else if ((h->flags & FLAG_ZERO) && h->precision < 0)
		ft_pad_left(&h->replace, '0', h->width);
	ft_pad_left(&h->replace, ' ', h->width);
}

void		ft_conversion_ux(t_holder *h, va_list args, const char *base)
{
	uintmax_t	u;

	u = ft_length(h, args);
	ft_precision(u, h, base);
	h->len = ft_strlen(h->replace);
}
