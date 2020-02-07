/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:00 by aroque            #+#    #+#             */
/*   Updated: 2020/02/06 22:42:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static char	*ft_handle_width(t_holder *h, char *src)
{
	char	pad;

	pad = ' ';
	if (h->flags & FLAG_MINUS)
		return (ft_padding_right(src, pad, h->width));
	return (ft_padding_left(src, pad, h->width));
}

char	*ft_handle_c(t_holder *h, va_list args)
{
	int		c;
	char	*dup;
	char	*replace;

	c = va_arg(args, int);
	if (!(dup = malloc(sizeof(char))))
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	if (!h->width)
		h->width++;
	replace = ft_handle_width(h, dup);
	free(dup);
	h->len = h->width;
	return (replace);
}
