/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:40:11 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 14:02:12 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Identify and parse each one of the flags,
**	width, precision, length modifers and conversion
**	specifiers passed as information to a format
**	placeholder. All this information is written
**	to a t_holder strucuture, to be later processed
**	with the va_list information.
*/

t_holder	*ft_parser(t_format *fmt)
{
	t_holder	*holder;

	holder = ft_holder_initializer();
	fmt->pos++;
	ft_parser_flags(fmt, holder);
	ft_parser_width(fmt, holder);
	ft_parser_precision(fmt, holder);
	ft_parser_length(fmt, holder);
	ft_parser_conversion(fmt, holder);
	return (holder);
}
