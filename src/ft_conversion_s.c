/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 02:55:37 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width(t_holder *h, char *src)
{
	char	pad;

	pad = ' ';
	if (h->flags & FLAG_MINUS)
		return (ft_pad_right(src, pad, h->width));
	if (h->flags & FLAG_ZERO)
		pad = '0';
	return (ft_pad_left(src, pad, h->width));
}

char		*ft_conversion_s(t_holder *h, va_list args)
{
	char	*src;
	char	*tmp;
	char	*replace;

	src = va_arg(args, char *);
	if (src == NULL)
		src = ft_strdup(STR_NULL);
	if (h->precision < 0)
		h->precision = ft_strlen(src);
	if (!(tmp = malloc((h->precision + 1) * sizeof(*tmp))))
		return (NULL);
	ft_strlcpy(tmp, src, h->precision + 1);
	replace = ft_width(h, tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
