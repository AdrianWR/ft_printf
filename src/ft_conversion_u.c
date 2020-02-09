/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:29:59 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 17:07:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_precision(uintmax_t u, t_holder *h, char *base)
{
	char *tmp;
	char hash_start[3];

	hash_start[0] = '0';
	hash_start[1] = h->conversion;
	if (u == 0 && h->precision == 0)
		tmp = (ft_strdup(STR_EMPTY));
	else
		tmp = ft_pad_left(ft_uitoa_base(u, base), '0', h->precision);
	if (u > 0 && h->conversion != 'u' && h->flags & FLAG_HASH)
		return (ft_strjoin(hash_start, tmp));
	return (tmp);
}

static char	*ft_width(char *src, t_holder *h)
{
	char	pad;
	char	*dest;
	int		src_len;

	pad = ' ';
	src_len = (int)ft_strlen(src);
	if (h->width <= src_len)
		return (ft_strdup(src));
	if (h->flags & FLAG_MINUS)
		dest = ft_pad_right(src, pad, h->width);
	else
	{
		if ((h->flags & FLAG_ZERO) && h->precision < 0)
			pad = '0';
		dest = ft_pad_left(src, pad, h->width);
		if (pad == '0' && src[1] == h->conversion)
		{
			dest[1] = h->conversion; 
			dest[h->width - src_len + 1] = pad;
		}
	}
	return (dest);
}

char		*ft_conversion_ux(t_holder *h, va_list args, char *base)
{
	uintmax_t	u;
	char		*replace;
	char		*tmp;

	u = ft_length(h, args);
	tmp = ft_precision(u, h, base);
	replace = ft_width(tmp, h);
	free(tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
