/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:00 by adrian            #+#    #+#             */
/*   Updated: 2020/02/05 16:39:44 by adrian           ###   ########.fr       */
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
	size_t	len;

	len = sizeof(char) + 1;
	c = va_arg(args, int);
	if (!(dup = malloc(len)))
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	return (ft_handle_width(h, dup));
}
