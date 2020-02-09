/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:15:50 by adrian            #+#    #+#             */
/*   Updated: 2020/02/08 23:59:18 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_handle_precision(unsigned int u, t_holder *h, char *base)
{
	if (u == 0 && h->precision == 0)
		return (ft_strdup(STR_EMPTY));
	return (ft_pad_left(ft_itoa_ubase(u, base), '0', h->precision));
}

static char	*ft_handle_width(char *src, t_holder *h)
{
	char	pad;
	char	*dest;

	pad = ' ';
	if (h->width <= (int)ft_strlen(src))
		return (ft_strdup(src));
	if (h->flags & FLAG_MINUS)
		dest = ft_pad_right(src, pad, h->width);
	else
	{
		if ((h->flags & FLAG_ZERO) && h->precision < 0)
			pad = '0';
		dest = ft_pad_left(src, pad, h->width);
	}
	return (dest);
}

char		*ft_handle_ux(t_holder *h, va_list args, char *base)
{
	char	*replace;
	char	*tmp;

	tmp = ft_handle_precision(va_arg(args, unsigned int), h, base);
	replace = ft_handle_width(tmp, h);
	free(tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
