/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:03:20 by aroque            #+#    #+#             */
/*   Updated: 2020/02/05 15:45:58 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>


void	ft_replace_conversion(t_holder *h, va_list args)
{
	if (h->conversion == 'd' || h->conversion == 'i')
		h->replace = ft_handle_d(h, args);
	else if (h->conversion == 'u')
		h->replace = ft_handle_uxX(h, args, DEC_BASE);
	else if (h->conversion == 'x')
		h->replace = ft_handle_uxX(h, args, HEX_BASE_L);
	else if (h->conversion == 'X')
		h->replace = ft_handle_uxX(h, args, HEX_BASE_U);
	else if (h->conversion == 's')
		h->replace = ft_handle_s(h, args);
	else if (h->conversion == 'c')
		h->replace = ft_handle_c(h, args);
	else if (h->conversion == 'p')
		h->replace = ft_handle_p(h, args);
	else if (h->conversion == '%')
		h->replace = ft_handle_pct();
	else
		h->replace = ft_strdup("");
	h->len = ft_strlen(h->replace);
}

/*
**	Insert some padding characters to a string
** 	accordingly to a given width. 
*/

char	*ft_padding_left(char *src, char pad, int width)
{
	char *dest;
	size_t len;

	len = ft_strlen(src);
	if (!(dest = malloc(ft_abs(width) + 1)))
		return (NULL);
	if (ft_abs(width) < len || !width)
		return (src);
	ft_memset(dest, pad, width - len);
	dest[width - len] = '\0';
	ft_strlcat(dest, src, width + 1);
	return (dest);
}

char	*ft_padding_right(char *src, char pad, int width)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	if (!(dest = malloc(ft_abs(width) + 1)))
		return (NULL);
	if (ft_abs(width) < len || !width)
		return (src);
	ft_strlcpy(dest, src, len + 1);
	ft_memset(dest + len, pad, width - len);
	dest[width] = '\0';
	return (dest);
}

//void	ft_replace_width(t_holder *h)
//{
//	char	*src;
//	char	pad;
//
//	pad = ' ';
//	src = ft_strdup(h->replace);
//	free(h->replace);
//	if (h->flags & FLAG_MINUS)
//	{
//		h->replace = ft_padding_right(src, pad, h->width);
//		return ;
//	}
//	if (h->flags & FLAG_ZERO)
//		pad = '0';
//	h->replace = ft_padding_left(src, pad, h->width);
//}
//
//void	ft_replace_precision(t_holder *h)
//{
//	char *src;
//
//	src = ft_strdup(h->replace);
//	if (h->precision >= 0)
//	{
//		if (ft_memchr("diouxX", h->conversion, 6))
//		{
//			free(h->replace);
//			h->replace = ft_padding_left(src, '0', h->precision);
//		}
//		else if (h->conversion == 'p' && h->precision == 0)
//		{
//			free(h->replace);
//			h->replace = ft_strdup("0x");
//		}
//	}
//	free(src);
//}
