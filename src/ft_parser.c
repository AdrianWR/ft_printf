/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:40:11 by aroque            #+#    #+#             */
/*   Updated: 2020/02/10 15:36:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
