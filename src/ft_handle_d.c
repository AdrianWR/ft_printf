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

static char	*ft_handle_precision(int d, t_holder *h)
{
	int		len;
	char	*src;
	char	*dest;

	if (d == 0 && h->precision >= 0)
		src = ft_strdup(STR_EMPTY);
	else
		src = ft_itoa_base(d, DEC_BASE);
	len = (int)ft_strlen(src);
	if (h->precision >= 0 && h->precision > len)
	{
		if (src[0] == '-')
		{
			dest = ft_padding_left(src, '0', h->precision + 1);
			dest[0] = '-';
			dest[h->precision - len + 1] = '0';
		}
		else
			dest = ft_padding_left(src, '0', h->precision);
	}
	else
		dest = ft_strdup(src);
	free(src);
	return (dest);
}

static char	*ft_handle_width(char *src, t_holder *h)
{
	char	pad;
	char 	*dest;

	pad = ' ';
	if (!(dest = malloc(h->width + 1)))
		return (NULL);
	if (h->flags & FLAG_MINUS)
		dest = ft_padding_right(src, pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO && h->precision < 0)
			pad = '0';
		dest = ft_padding_left(src, pad, h->width);
		if (src[0] == '-' && pad == '0')
		{
			dest[0] = '-';
			dest[h->width - ft_strlen(src)] = pad;
		}
	}
	//free(src);
	return (dest);
}

char	*ft_handle_d(t_holder *h, va_list args)
{
	char	*replace;
	char	*tmp;

	tmp = ft_handle_precision(va_arg(args, int), h);
	if (h->width > (int)ft_strlen(tmp))
		replace = ft_handle_width(tmp, h);
	else
		replace = ft_strdup(tmp);
	free(tmp);
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
