/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/07 20:13:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_handle_width(t_holder *h, char *src)
{
	char	pad;

	pad = ' ';
	if (h->flags & FLAG_MINUS)
		return (ft_padding_right(src, pad, h->width));
	if (h->flags & FLAG_ZERO)
		pad = '0';
	return (ft_padding_left(src, pad, h->width));
}

char	*ft_handle_s(t_holder *h, va_list args)
{
	char	*src;
	char	*tmp;
	char	*replace;

	src = va_arg(args, char *);
	if (src == NULL)
		src = ft_strdup(STR_NULL);
	if (h->precision < 0)
		h->precision = ft_strlen(src);
	if (!(tmp = malloc((h->precision + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(tmp, src, h->precision + 1);
	replace = ft_handle_width(h, tmp);
	h->len = ft_strlen(replace);
	return (replace);
}
