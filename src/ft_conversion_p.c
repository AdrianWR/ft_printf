/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 15:24:37 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision(t_holder *h, void *p)
{
	if (!p)
	{
		h->replace = ft_strdup("0");
		h->len = 1;
	}
	else
	{
		h->replace = ft_uitoa_base((uintptr_t)p, HEX_BASE_L);
		h->len = ft_strlen(h->replace);
	}
	if (h->flags & FLAG_MINUS)
	{
		ft_pad_left(&h->replace, 'x', ++h->len);
		ft_pad_left(&h->replace, ZERO, ++h->len);
		ft_pad_right(&h->replace, SPACE, h->width);
	}
	else if (h->flags & FLAG_ZERO)
	{
		ft_pad_left(&h->replace, ZERO, h->width);
		ft_pad_left(&h->replace, 'x', ++h->len);
		ft_pad_left(&h->replace, ZERO, ++h->len);
	}
	else
	{
		ft_pad_left(&h->replace, 'x', ++h->len);
		ft_pad_left(&h->replace, ZERO, ++h->len);
		ft_pad_left(&h->replace, SPACE, h->width);
	}
}

void		ft_conversion_p(t_holder *h, va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	ft_precision(h, p);
	h->len = ft_strlen(h->replace);
}
