/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:29:59 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 14:07:02 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

static void			ft_alternate(uintmax_t u, t_holder *h)
{
	h->len = ft_strlen(h->replace);
	if (h->flags & FLAG_HASH)
	{
		if (!u)
			return ;
		if (h->conversion == 'x' || h->conversion == 'X')
			ft_pad_left(&h->replace, h->conversion, ++h->len);
		ft_pad_left(&h->replace, ZERO, ++h->len);
	}
}

static void			ft_conversion(uintmax_t u, t_holder *h, const char *base)
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
	ft_alternate(u, h);
	if ((h->flags & FLAG_ZERO) && h->precision < 0)
	{
		ft_pad_left(&h->replace, ZERO, h->width);
		if (h->width > (int)h->len && h->flags & FLAG_HASH && u)
			ft_swap(&h->replace[1], &h->replace[h->width - h->len + 1]);
	}
	else if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, ' ', h->width);
	else
		ft_pad_left(&h->replace, ' ', h->width);
}

void				ft_conversion_ux(t_holder *h, va_list args, const char *b)
{
	uintmax_t	u;

	u = ft_length(h, args);
	ft_conversion(u, h, b);
	h->len = ft_strlen(h->replace);
}
