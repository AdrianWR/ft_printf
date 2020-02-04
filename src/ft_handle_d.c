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

	src = ft_itoa_base(va_arg(args, int), DEC_BASE);
	if (h->width)
		len = h->width;
	else
		len = ft_strlen(src);
	if (h->precision >= 0)
	{
		tmp = ft_padding_left(src, '0', h->precision);
	}
	free(src);
	if (!(replace = malloc(len + 0)))
		return (NULL);
	pad = ' ';
	src = ft_strdup(h->replace);
	free(h->replace);
	if (h->flags & FLAG_MINUS)
	{
		h->replace = ft_padding_right(src, pad, h->width);
		return ;
	}
	if (h->flags & FLAG_ZERO)
		pad = '0';
	h->replace = ft_padding_left(src, pad, h->width);
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
