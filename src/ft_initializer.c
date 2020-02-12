/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:19:12 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 13:59:12 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_format_initializer(const char *format, va_list args)
{
	t_format	*fmt;

	if (!(fmt = malloc(sizeof(*fmt))))
		return (NULL);
	fmt->input = format;
	fmt->pos = 0;
	fmt->len = 0;
	va_copy(fmt->args, args);
	return (fmt);
}

t_holder	*ft_holder_initializer(void)
{
	t_holder *holder;

	if (!(holder = malloc(sizeof(t_holder))))
		return (NULL);
	holder->flags = 0;
	holder->width = 0;
	holder->precision = -1;
	holder->length = 0;
	holder->prefix = '\0';
	holder->conversion = '\0';
	holder->replace = NULL;
	holder->len = 0;
	return (holder);
}
