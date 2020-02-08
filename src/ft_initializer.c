/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:19:12 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 19:27:04 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_format_initializer(const char *format, va_list args)
{
	t_format	*fmt;

	if(!(fmt = malloc(sizeof(*fmt))))
		return (NULL);
	fmt->input = format;
	fmt->pos = 0;
	fmt->len = 0;
	va_copy(fmt->args, args);
	return (fmt);
}
