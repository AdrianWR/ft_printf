/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:00 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 21:48:50 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wint_t	ft_length(t_holder *h, va_list args)
{
	wint_t	c;

	if (h->length & L_LONG)
		c = (wint_t)(va_arg(args, wint_t));
	else
		c = (int)(va_arg(args, int));
	return ((wint_t)c);
}

void			ft_conversion_c(t_holder *h, va_list args)
{
	wint_t	c;

	c = ft_length(h, args);
	if (!h->width)
		h->width += 1;
	h->replace = malloc(h->width);
	ft_memset(h->replace, SPACE, h->width);
	if (h->flags & FLAG_MINUS)
		h->replace[0] = c;
	else
		h->replace[h->width - 1] = c;
	h->len = h->width;
}
