/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:09:49 by aroque            #+#    #+#             */
/*   Updated: 2020/02/06 22:48:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_handle_pct(t_holder *h)
{
	char	pad;
	char	*src;

	pad = ' ';
	if (h->flags & FLAG_MINUS)
		src = ft_padding_right("%", pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO)
			pad = '0';
		src = ft_padding_left("%", pad, h->width);
	}
	h->len = ft_strlen(src);
	return (src);
}
