/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exceptions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:56:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/02 18:22:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

char	*ft_handle_s(char *str)
{
	char *s;

	if (str == NULL)
	{
		s = ft_strdup("(null)");
	}
	else
		s = ft_strdup(str);
	return (s);
}

char	*ft_handle_d(t_holder *h, va_list args)
{
	if (h->length & L_SHORT)
		return (ft_itoa_base((short)(va_arg(args, int)), DEC_BASE));
	else if (h->length & L_CHAR)
		return (ft_itoa_base((char)(va_arg(args, int)), DEC_BASE));
	else if (h->length & L_LONG)
		return (ft_itoa_base((va_arg(args, long)), DEC_BASE));
	else if (h->length & L_LONG)
		return (ft_itoa_base((va_arg(args, long long)), DEC_BASE));
	return (ft_itoa_base((va_arg(args, int)), DEC_BASE));
}
