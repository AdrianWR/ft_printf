/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:00 by aroque            #+#    #+#             */
/*   Updated: 2020/02/07 20:11:41 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_handle_width(t_holder *h, char src)
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

char	*ft_handle_c(t_holder *h, va_list args)
{
	int		c;
	char	*replace;

	c = va_arg(args, int);
	if (!h->width)
		h->width++;
	replace = ft_handle_width(h, c);
	h->len = h->width;
	return (replace);
}
