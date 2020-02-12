/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 10:26:05 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conversion_s(t_holder *h, va_list args)
{
	char	*tmp;

	tmp = ft_strdup(va_arg(args, char *));
	if (!tmp)
		tmp = ft_strdup(STR_NULL);
	if (h->precision < 0)
		h->precision = (int)ft_strlen(tmp);
	h->replace = malloc(h->precision + 1);
	ft_strlcpy(h->replace, tmp, h->precision + 1);
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, SPACE, h->width);
	else if (h->flags & FLAG_ZERO)
		ft_pad_left(&h->replace, ZERO, h->width);
	else
		ft_pad_left(&h->replace, SPACE, h->width);
	free(tmp);
	h->len = ft_strlen(h->replace);
}
