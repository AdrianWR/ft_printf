/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:40:11 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 17:39:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

t_holder	*ft_holder_initializer(void)
{
	t_holder *holder;

	if (!(holder = malloc(sizeof(t_holder))))
		return (NULL);
	holder->minus = 0;
	holder->plus = 0;
	holder->zero = 0;
	holder->hash = 0;
	holder->width = 0;
	holder->precision = 0;
	holder->conversion = '\0';
	return (holder);
}

static void	ft_parser_conversion(char **str, t_holder *holder)
{
	int i;
	int len;
	char *conversions;

	i = 0;
	len = ft_strlen(PLACEHOLDER_CONVERSIONS);
	conversions = ft_strdup(PLACEHOLDER_CONVERSIONS);
	while (i < len)
	{
		if (**str == conversions[i])
			holder->conversion = conversions[i];
		i++;
	}
	free(conversions);
	(*str)++;
}

static void	ft_parser_flags(char **str, t_holder *holder)
{
	while (ft_strchr(PLACEHOLDER_FLAGS, **str))
	{
		if (**str == '-')
			holder->minus = 1;
		else if (**str == '0')
			holder->zero = 1;
		else if (**str == '+')
			holder->plus = 1;
		else if (**str == '#')
			holder->hash = 1;
		(*str)++;
	}
}

static void	ft_parser_width(char **str, t_holder *holder)
{
	holder->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
}

//static void	ft_parser_precision(char **str, t_holder *holder)
//{
//	holder
//}

//static void	ft_parser_dump(t_holder *holder)
//{
//	ft_putstr("\n-------- FLAGS --------");
//	ft_putstr("\nMinus: ");
//	ft_putnbr(holder->minus);
//	ft_putstr("\nPlus: ");
//	ft_putnbr(holder->plus);
//	ft_putstr("\nZero: ");
//	ft_putnbr(holder->zero);
//	ft_putstr("\nHash: ");
//	ft_putnbr(holder->hash);
//	ft_putstr("\n-------- WIDTH --------");
//	ft_putstr("\nWidth: ");
//	ft_putnbr(holder->width);
//	ft_putstr("\n-------- CONVERSION --------");
//	ft_putstr("\nConversion: ");
//	ft_putchar(holder->conversion);
//	ft_putchar('\n');
//}

t_holder	*ft_parser(char **str)
{
	t_holder	*holder;

	holder = ft_holder_initializer();
	ft_parser_flags(str, holder);
	ft_parser_width(str, holder);
	//ft_parser_precision(str, holder);
	//ft_parser_length();
	ft_parser_conversion(str, holder);
	//ft_parser_dump(holder);
	return (holder);
}
