/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_dump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:17:39 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:23:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_dump(t_holder *holder)
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
