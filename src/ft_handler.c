/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:08:24 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 18:00:20 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	ft_handler_conversion(t_holder *holder, va_list args)
{
	size_t	len;

	len = 0;
	if (holder->conversion == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (holder->conversion == 'c')
		len += ft_putchar(va_arg(args, int));
	if (holder->conversion == 's')
		len += ft_putstr(va_arg(args, char *));
	if (holder->conversion == 'x')
		len += ft_puthex(va_arg(args, int));
	return (len);
}

size_t	ft_handler(t_holder *holder, va_list args)
{
	size_t len;

	len = 0;
	len += ft_handler_conversion(holder, args);	
	return (len);
}
