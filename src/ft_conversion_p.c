/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 18:57:37 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conversion(t_holder *h, void *p)
{
	if (!p)
	{
		if (!h->precision)
			h->replace = ft_strdup(STR_EMPTY);
		else
			h->replace = ft_strdup("0");
	}
	else
		h->replace = ft_uitoa_base((uintptr_t)p, HEX_BASE_L);
	h->len = ft_strlen(h->replace);
	if (h->precision > (int)h->len)
		h->len = h->precision;
	ft_pad_left(&h->replace, ZERO, h->len);
	ft_pad_left(&h->replace, X, ++h->len);
	ft_pad_left(&h->replace, ZERO, ++h->len);
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, SPACE, h->width);
	else
		ft_pad_left(&h->replace, SPACE, h->width);
}

void		ft_conversion_p(t_holder *h, va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	ft_conversion(h, p);
	h->len = ft_strlen(h->replace);
}
