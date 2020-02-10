/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:03:20 by aroque            #+#    #+#             */
/*   Updated: 2020/02/10 15:45:13 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_replace(t_holder *h, va_list args)
{
	if (h->conversion == 'd' || h->conversion == 'i')
		h->replace = ft_conversion_d(h, args);
	else if (h->conversion == 'u')
		h->replace = ft_conversion_ux(h, args, DEC_BASE);
	else if (h->conversion == 'x')
		h->replace = ft_conversion_ux(h, args, HEX_BASE_L);
	else if (h->conversion == 'X')
		h->replace = ft_conversion_ux(h, args, HEX_BASE_U);
	else if (h->conversion == 's')
		h->replace = ft_conversion_s(h, args);
	else if (h->conversion == 'c')
		h->replace = ft_conversion_c(h, args);
	else if (h->conversion == 'p')
		h->replace = ft_conversion_p(h, args);
	else if (h->conversion == '%')
		h->replace = ft_conversion_pct(h);
	else if (h->conversion == 'n')
		h->replace = ft_conversion_pct(h);
	else if (h->conversion == 'f')
		h->replace = ft_conversion_f(h, args);
	else if (h->conversion == 'g')
		h->replace = ft_conversion_pct(h);
	else if (h->conversion == 'e')
		h->replace = ft_conversion_pct(h);
}

/*
**	Insert some pad characters to a string
** 	accordingly to a given width.
*/

void	ft_pad_left(char *src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(src);
	if (width < (int)len || !width)
		width = len;
	if (!(tmp = malloc(width + 1)))
		return ;
	ft_memset(tmp, pad, width - len);
	tmp[width - len] = '\0';
	ft_strlcat(tmp, src, width + 1);
	src = tmp;
	free(tmp);
}

void	ft_pad_right(char *src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(src);
	if (width < (int)len || !width)
		width = len;
	if (!(tmp = malloc(width + 1)))
		return ;
	ft_strlcpy(tmp, src, len + 1);
	ft_memset(tmp + len, pad, width - len);
	tmp[width] = '\0';
	src = tmp;
	free(tmp);
}

void	ft_prefix(t_holder *h)
{
	int len;

	len = (int)ft_strlen(h->replace) + 1;
	ft_pad_left(h->replace, h->prefix, len);
}
