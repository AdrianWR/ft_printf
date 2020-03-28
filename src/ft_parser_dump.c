/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_dump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:17:39 by aroque            #+#    #+#             */
/*   Updated: 2020/03/28 16:50:10 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_dump(t_holder *holder)
{
	ft_putstr_fd("\n--------- FLAGS ---------", STDOUT_FILENO);
	ft_putstr_fd("\nMinus: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->flags & FLAG_MINUS, STDOUT_FILENO);
	ft_putstr_fd("\nPlus: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->flags & FLAG_PLUS, STDOUT_FILENO);
	ft_putstr_fd("\nZero: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->flags & FLAG_ZERO, STDOUT_FILENO);
	ft_putstr_fd("\nHash: ", STDOUT_FILENO);
	ft_putnbr_fd((holder->flags & FLAG_HASH), STDOUT_FILENO);
	ft_putstr_fd("\n--------- WIDTH ---------", STDOUT_FILENO);
	ft_putstr_fd("\nWidth: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->width, STDOUT_FILENO);
	ft_putstr_fd("\n------- PRECISION -------", STDOUT_FILENO);
	ft_putstr_fd("\nPrecision: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->precision, STDOUT_FILENO);
	ft_putstr_fd("\n-------- LENGTH --------", STDOUT_FILENO);
	ft_putstr_fd("\nLength: ", STDOUT_FILENO);
	ft_putnbr_fd(holder->length, STDOUT_FILENO);
	ft_putstr_fd("\n------- CONVERSION -------", STDOUT_FILENO);
	ft_putstr_fd("\nConversion: ", STDOUT_FILENO);
	ft_putchar_fd(holder->conversion, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
