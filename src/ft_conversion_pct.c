/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:36:43 by aroque            #+#    #+#             */
/*   Updated: 2020/02/10 20:46:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conversion_pct(t_holder *h)
{
	char	pad;

	pad = ' ';
	h->replace = ft_strdup("%");
	if (!h->width)
		h->width++;
	if (h->flags & FLAG_MINUS)
		ft_pad_right(h->replace, pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO)
			pad = '0';
		ft_pad_left(h->replace, pad, h->width);
	}
	h->len = ft_strlen(h->replace);
	return (h->replace);
}
