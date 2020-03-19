/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:46:09 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 04:46:26 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** These functions aim to reproduce the same behavior as its
** counterparts on <stdio.h> library. Further information should
** be get on its manual page (probably man 3 printf)
**
** Besides the implementation of the mandatory ft_printf function,
** I found useful to implmement sister functions of the printf
** family, which are the following ones:
** -> ft_vprintf:  Writes the formatted string to STDOUT_FILENO.
**                 Takes a va_list as parameter.
** -> ft_dprintf:  Writes the formatted string to a file descriptor.
**                 Takes variadic arguments as parameter.
** -> ft_vdprintf: Writes the formatted string to a file descriptor.
**                 Takes a va_list as parameter.
** All the functions have the same return as ft_printf, which are the
** number of bytes written succesfullly.
*/

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(STDOUT_FILENO, format, args));
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int			len;
	t_format	*fmt;

	fmt = ft_format_initializer(format, args);
	while (fmt->input[fmt->pos])
	{
		if (fmt->input[fmt->pos] == '%')
			ft_placeholder(fd, fmt);
		else
		{
			fmt->len += ft_putchar_fd(fmt->input[fmt->pos], fd);
			fmt->pos++;
		}
	}
	len = fmt->len;
	va_end(fmt->args);
	free(fmt);
	return (len);
}
