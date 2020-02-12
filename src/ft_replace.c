/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:03:20 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 21:48:24 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_replace(t_holder *h, va_list args)
{
	if (h->conversion == 'd' || h->conversion == 'i')
		ft_conversion_d(h, args);
	else if (h->conversion == 'u')
		ft_conversion_ux(h, args, DEC_BASE);
	else if (h->conversion == 'x')
		ft_conversion_ux(h, args, HEX_BASE_L);
	else if (h->conversion == 'X')
		ft_conversion_ux(h, args, HEX_BASE_U);
	else if (h->conversion == 's')
		ft_conversion_s(h, args);
	else if (h->conversion == 'c')
		ft_conversion_c(h, args);
	else if (h->conversion == 'p')
		ft_conversion_p(h, args);
	else if (h->conversion == '%')
		ft_conversion_pct(h);
	//else if (h->conversion == 'n')
	//	h->replace = ft_conversion_pct(h);
	else if (h->conversion == 'f')
		ft_conversion_f(h, args);
	//else if (h->conversion == 'g')
	//	h->replace = ft_conversion_pct(h);
	//else if (h->conversion == 'e')
	//	h->replace = ft_conversion_pct(h);
}

/*
**	Insert some pad characters to a string
** 	accordingly to a given width.
*/

void	ft_pad_left(char **src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*src);
	if (width < (int)len || !width)
		width = len;
	if (!(tmp = malloc(width + 1)))
		return ;
	ft_memset(tmp, pad, width - len);
	tmp[width - len] = '\0';
	ft_strlcat(tmp, *src, width + 1);
	free(*src);
	*src = tmp;
}

void	ft_pad_right(char **src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*src);
	if (width < (int)len || !width)
		width = len;
	if (!(tmp = malloc(width + 1)))
		return ;
	ft_strlcpy(tmp, *src, len + 1);
	ft_memset(tmp + len, pad, width - len);
	tmp[width] = '\0';
	free(*src);
	*src = tmp;
}

void	ft_prefix(t_holder *h)
{
	int len;

	if (h->prefix)
	{
		len = (int)ft_strlen(h->replace) + 1;
		ft_pad_left(&h->replace, h->prefix, len);
	}
}
