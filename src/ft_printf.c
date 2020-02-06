/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:46:09 by aroque            #+#    #+#             */
/*   Updated: 2020/02/06 15:42:21 by adrian           ###   ########.fr       */
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

t_format	*ft_format_initializer(const char *format, va_list args)
{
	t_format	*fmt;

	if(!(fmt = malloc(sizeof(*fmt))))
		return (NULL);
	fmt->input = (char *)format;
	fmt->output = ft_strdup("");
	fmt->start = 0;
	fmt->pos = 0;
	fmt->len = 0;
	va_copy(fmt->args, args);
	return (fmt);
}

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(1, format, args));
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	size_t		len_input;
	int			len;
	t_format	*fmt;

	fmt = ft_format_initializer(format, args);
	len_input = ft_strlen(fmt->input);
	while (fmt->pos <= len_input)
	{
		if (fmt->input[fmt->pos] == '%' || !fmt->input[fmt->pos])
		{
			ft_pre_output(fmt);
			if (fmt->input[fmt->pos] == '%')
				ft_process(fmt);
		}
		fmt->pos++;
	}
	len = fmt->len;
	write(fd, fmt->output, len);
	free(fmt->output);
	free(fmt);
	return (len);
}
