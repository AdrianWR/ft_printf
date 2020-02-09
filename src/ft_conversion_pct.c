/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:36:43 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 02:41:55 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conversion_pct(t_holder *h)
{
	char	pad;
	char	*src;

	pad = ' ';
	if (!h->width)
		h->width++;
	if (h->flags & FLAG_MINUS)
		src = ft_pad_right("%", pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO)
			pad = '0';
		src = ft_pad_left("%", pad, h->width);
	}
	h->len = ft_strlen(src);
	return (src);
}
