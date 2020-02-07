/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/06 22:43:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_handle_precision(t_holder *h, void *p)
{
	char	*ptr;
	char	*tmp;

	if (!p)	
	{
		if (h->precision < 0)
			h->precision = 1;
		if (!(ptr = malloc(h->precision + 1)))
			return (NULL);
		ptr = ft_memset(ptr, '0', h->precision);
		ptr[h->precision + 1] = '\0';
	}
	else
	{
		tmp = ft_itoa_ubase((long unsigned int)p, HEX_BASE_L);
		if (h->precision >= 0 && h->precision > (int)ft_strlen(tmp))
			ptr = ft_padding_left(tmp, '0', h->precision);
		else
			ptr = ft_strdup(tmp);
		free(tmp);
	}
	return (ptr);
}

static char	*ft_handle_width(t_holder *h, char *src)
{
	if (!h->width)
		return (src);
	if (h->flags & FLAG_MINUS)
		return (ft_padding_right(src, ' ', h->width));
	return (ft_padding_left(src, ' ', h->width));
}

char	*ft_handle_p(t_holder *h, va_list args)
{
	void	*p;
	char	*ptr;
	char	*dup;
	size_t	len;

	p = va_arg(args, void *);
	len = ft_strlen(PTR_START) + 1;
	if (h->precision >= 0)
		len += h->precision;
	else
		len += sizeof(p);
	if (!(dup = ft_calloc(len, sizeof(unsigned char))))
		return (NULL);
	ft_strlcpy(dup, PTR_START, ft_strlen(PTR_START) + 1);
	ptr = ft_handle_precision(h, p);
	ft_strlcat(dup, ptr, len + 1);
	free(ptr);
	return (ft_handle_width(h, dup));
}
