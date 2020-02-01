/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:03:20 by aroque            #+#    #+#             */
/*   Updated: 2020/02/01 02:00:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

char	*ft_chardup(int c)
{
	char *dup;

	if(!(dup = malloc(sizeof(char))))
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	return (dup);
}

void	ft_replace_conversion(t_holder *h, va_list args)
{
	if (h->conversion == 'd' || h->conversion == 'i')
		h->replace = ft_itoa_base((va_arg(args, int)), DEC_BASE);
	else if (h->conversion == 'u')
		h->replace = ft_itoa_base((va_arg(args, unsigned int)), DEC_BASE);
	else if (h->conversion == 'x')
		h->replace = ft_itoa_base((va_arg(args, int)), HEX_BASE_L);
	else if (h->conversion == 'X')
		h->replace = ft_itoa_base((va_arg(args, int)), HEX_BASE_U);
	else if (h->conversion == 's')
		h->replace = ft_strdup(va_arg(args, char *));
	else if (h->conversion == 'c')
		h->replace = ft_chardup(va_arg(args, int));
	else if (h->conversion == '%')
		h->replace = ft_chardup('%');
	h->len = ft_strlen(h->replace);
}

void	ft_replace_width(t_holder *h)
{
	char	*src;

	if ((size_t)h->width <= h->len)
		return ;
	src = ft_strdup(h->replace);
	free(h->replace);
	h->replace = malloc(h->width + 1);
	ft_memset(h->replace, ' ', h->width - h->len);
	h->replace[h->width - h->len] = '\0';
	h->len = ft_strlcat(h->replace, src, h->width + 1);
	free(src);
}
//ft_replace_precision();
//ft_replace_flags();
