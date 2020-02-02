/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:40:11 by aroque            #+#    #+#             */
/*   Updated: 2020/02/02 15:55:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_holder	*ft_holder_initializer(void)
{
	t_holder *holder;

	if (!(holder = malloc(sizeof(t_holder))))
		return (NULL);
	holder->flags = 0;
	holder->width = 0;
	holder->precision = -1;
	holder->length = 0;
	holder->conversion = '\0';
	holder->replace = NULL;
	holder->len = 0;
	return (holder);
}

static void	ft_parser_dump(t_holder *holder)
{
	ft_putstr("\n--------- FLAGS ---------");
	ft_putstr("\nMinus: ");
	ft_putnbr(holder->flags & FLAG_MINUS);
	ft_putstr("\nPlus: ");
	ft_putnbr(holder->flags & FLAG_PLUS);
	ft_putstr("\nZero: ");
	ft_putnbr(holder->flags & FLAG_ZERO);
	ft_putstr("\nHash: ");
	ft_putnbr((holder->flags & FLAG_HASH));
	ft_putstr("\n--------- WIDTH ---------");
	ft_putstr("\nWidth: ");
	ft_putnbr(holder->width);
	ft_putstr("\n------- PRECISION -------");
	ft_putstr("\nPrecision: ");
	ft_putnbr(holder->precision);
	ft_putstr("\n-------- LENGTH --------");
	ft_putstr("\nLength: ");
	ft_putnbr(holder->length);
	ft_putstr("\n------- CONVERSION -------");
	ft_putstr("\nConversion: ");
	ft_putchar(holder->conversion);
	ft_putchar('\n');
}
#include <stdio.h>
t_holder	*ft_parser(t_format *fmt)
{
	t_holder	*holder;

	holder = ft_holder_initializer();
	ft_parser_flags(fmt, holder);
	ft_parser_width(fmt, holder);
	ft_parser_precision(fmt, holder);
	ft_parser_length(fmt, holder);
	ft_parser_conversion(fmt, holder);
	(void) ft_parser_dump;
	//ft_parser_dump(holder);
	return (holder);
}
