/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:36:43 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 12:09:24 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_pct(t_holder *h)
{
	h->replace = ft_strdup("%");
	if (!h->width)
		h->width++;
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, SPACE, h->width);
	else if (h->flags & FLAG_ZERO)
		ft_pad_left(&h->replace, ZERO, h->width);
	else
		ft_pad_left(&h->replace, SPACE, h->width);
	h->len = ft_strlen(h->replace);
}
