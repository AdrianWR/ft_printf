/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:15:50 by adrian            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:13 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_handle_precision(unsigned int u, t_holder *h, char *base)
{
	int		len;
	char	*src;
	char	*dest;

	if (u == 0 && h->precision >= 0)
		src = ft_strdup(STR_EMPTY);
	else
		src = ft_itoa_ubase(u, base);
	len = (int)ft_strlen(src);
	if (h->precision >= 0 && h->precision > len)
		dest = ft_padding_left(src, '0', h->precision);
	else
		dest = ft_strdup(src);
	free(src);
	return (dest);
}

static char	*ft_handle_width(char *src, t_holder *h)
{
	char	pad;
	char 	*dest;

	pad = ' ';
	if (!(dest = malloc(h->width + 1)))
		return (NULL);
	if (h->flags & FLAG_MINUS)
		dest = ft_padding_right(src, pad, h->width);
	else
	{
		if (h->flags & FLAG_ZERO && h->precision < 0)
			pad = '0';
		dest = ft_padding_left(src, pad, h->width);
	}
	//free(src);
	return (dest);
}

char	*ft_handle_uxX(t_holder *h, va_list args, char *base)
{
	char	*replace;
	char	*tmp;

	tmp = ft_handle_precision(va_arg(args, unsigned int), h, base);
	if (h->width > (int)ft_strlen(tmp))
		replace = ft_handle_width(tmp, h);
	else
		replace = ft_strdup(tmp);
	free(tmp);
	return (replace);
}
