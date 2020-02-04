/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/03 23:24:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_handle_s_width(t_holder *h, char *src)
{
	char	pad;

	pad = ' ';
	if (h->flags & FLAG_MINUS)
		return (ft_padding_right(src, pad, h->width));
	return (ft_padding_left(src, pad, h->width));
}

char	*ft_handle_s(t_holder *h, va_list args)
{
	char	*src;
	char	*replace;

	src = va_arg(args, char *);
	if (src == NULL)
	{
		if (h->precision >= 0 && h->precision < (int)ft_strlen(STR_NULL))
			replace = ft_strdup(STR_EMPTY);
		else
			replace = ft_strdup(STR_NULL);
	}
	else
	{
		if (h->precision < 0)
			h->precision = ft_strlen(src);
		if (!(replace = malloc((h->precision + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(replace, src, h->precision + 1);
	}
	return (ft_handle_s_width(h, replace));
}

