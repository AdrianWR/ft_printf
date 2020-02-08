/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:46:09 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 19:28:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(1, format, args));
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int			len;
	t_format	*fmt;

	fmt = ft_format_initializer(format, args);
	while (fmt->input[fmt->pos])
	{
		if (fmt->input[fmt->pos] == '%')
			ft_process(fd, fmt);
		else
			fmt->len += ft_putchar_fd(fmt->input[fmt->pos], fd);
		if (fmt->input[fmt->pos])
			fmt->pos++;
	}
	len = fmt->len;
	va_end(fmt->args);
	free(fmt);
	return (len);
}
