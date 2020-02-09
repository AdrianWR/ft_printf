/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 02:58:21 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision(t_holder *h, void *p)
{
	char	*ptr;
	char	*tmp;

	if (!p)
	{
		if (h->precision < 0)
			h->precision = 1;
		ptr = malloc(h->precision + 1);
		ptr = ft_memset(ptr, '0', h->precision);
		ptr[h->precision] = '\0';
	}
	else
	{
		tmp = ft_uitoa_base((long unsigned)p, HEX_BASE_L);
		if (h->precision >= 0 && h->precision > (int)ft_strlen(tmp))
			ptr = ft_pad_left(tmp, '0', h->precision);
		else
			ptr = ft_strdup(tmp);
		free(tmp);
	}
	return (ptr);
}

static char	*ft_width(t_holder *h, char *src)
{
	char	pad;

	pad = ' ';
	if (!h->width)
		return (ft_strdup(src));
	if (h->flags & FLAG_MINUS)
		return (ft_pad_right(src, pad, h->width));
	return (ft_pad_left(src, pad, h->width));
}

char		*ft_conversion_p(t_holder *h, va_list args)
{
	void	*p;
	char	*ptr;
	char	*tmp;

	p = va_arg(args, void *);
	h->len = ft_strlen(PTR_START) + 1;
	ptr = ft_precision(h, p);
	h->len += ft_strlen(ptr);
	if (!(tmp = malloc(h->len * sizeof(unsigned char))))
		return (NULL);
	ft_strlcpy(tmp, PTR_START, ft_strlen(PTR_START) + 1);
	ft_strlcat(tmp, ptr, h->len);
	free(ptr);
	ptr = ft_width(h, tmp);
	h->len = ft_strlen(ptr);
	return (ptr);
}
