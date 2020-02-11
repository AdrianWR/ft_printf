/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 00:48:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width(t_holder *h)
{
	if (h->flags & FLAG_MINUS)
		ft_pad_right(&h->replace, SPACE, h->width);
	else if (h->flags & FLAG_ZERO)
		ft_pad_left(&h->replace, ZERO, h->width);
	else
		ft_pad_left(&h->replace, SPACE, h->width);
}

void		ft_conversion_s(t_holder *h, va_list args)
{
	char	*tmp;

	tmp = ft_strdup(va_arg(args, char *));
	if (!tmp)
		h->replace = ft_strdup(STR_NULL);
	else
		h->replace = ft_strdup(tmp);
	if (h->precision < 0)
		h->precision = ft_strlen(h->replace);
	//if (!(tmp = malloc((h->precision + 1) * sizeof(*tmp))))
	//	return ;
	//ft_strlcpy(tmp, h->replace, h->precision + 1);
	ft_width(h);
	h->len = ft_strlen(h->replace);
}
