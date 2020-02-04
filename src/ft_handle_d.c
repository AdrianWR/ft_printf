/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:23:37 by aroque            #+#    #+#             */
/*   Updated: 2020/02/04 00:12:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_handle_d(t_holder *h, va_list args)
{
	char	*replace;
	char	*src;
	char	*tmp;
	char	pad;
	size_t	len;

	pad = ' ';
	src = ft_itoa_base(va_arg(args, int), DEC_BASE);
	if (h->width)
		len = h->width;
	else
		len = ft_strlen(src);
	if (h->precision >= 0 && h->precision > (int)len)
		tmp = ft_padding_left(src, '0', h->precision);
	else
		tmp = ft_strdup(src);
	free(src);
	if (!(replace = malloc(len + 1)))
		return (NULL);
	if (h->flags & FLAG_MINUS)
		replace = ft_padding_right(tmp, pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO)
			pad = '0';
		replace = ft_padding_left(tmp, pad, h->width);
	}
	return (replace);
}
	//if (h->length & L_SHORT)
	//	return (ft_itoa_base((short)(va_arg(args, int)), DEC_BASE));
	//else if (h->length & L_CHAR)
	//	return (ft_itoa_base((char)(va_arg(args, int)), DEC_BASE));
	//else if (h->length & L_LONG)
	//	return (ft_itoa_base((va_arg(args, long)), DEC_BASE));
	//else if (h->length & L_LONG)
	//	return (ft_itoa_base((va_arg(args, long long)), DEC_BASE));
	//return (ft_itoa_base((va_arg(args, int)), DEC_BASE));
