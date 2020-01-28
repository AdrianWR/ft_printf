/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:46:09 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 17:50:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list args)
{
	int			len;
	char		*str;
	t_holder	*holder;
	
	len = 0;
	str = ft_strdup(format);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			holder = ft_parser(&str);
			len += ft_handler(holder, args);
			//str++;
		}
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}
