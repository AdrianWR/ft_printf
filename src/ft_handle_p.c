/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/05 11:57:28 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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

	p = va_arg(args, void *);
	if (!(dup = ft_calloc(sizeof(p), sizeof(unsigned char))))
		return (NULL);
	dup[0] = '0';
	dup[1] = 'x';

	if (!p)
		ptr = ft_strdup("0");
	else
		ptr = ft_itoa_ubase((long unsigned int)p, HEX_BASE_L);
	ft_strlcat(dup, ptr,  2 * sizeof(p) - 1);
	//free(p);
	free(ptr);
	return (ft_handle_width(h, dup));
}
