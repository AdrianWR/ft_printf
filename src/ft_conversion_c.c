/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:00 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 16:58:11 by aroque           ###   ########.fr       */
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

static char	*ft_width(t_holder *h, wint_t src)
{
	char	pad;
	char	*dest;

	pad = ' ';
	if (!(dest = malloc(h->width)))
		return (NULL);
	ft_memset(dest, pad, h->width);
	if (h->flags & FLAG_MINUS)
		dest[0] = src;
	else
		dest[h->width - 1] = src;
	return (dest);
}

char		*ft_conversion_c(t_holder *h, va_list args)
{
	wint_t	c;
	char	*replace;

	c = ft_length(h, args);
	if (!h->width)
		h->width += 1;
	replace = ft_width(h, c);
	h->len = h->width;
	return (replace);
}
