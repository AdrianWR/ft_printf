/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:15:20 by aroque            #+#    #+#             */
/*   Updated: 2020/01/31 23:45:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_parser_flags(t_format *fmt, t_holder *holder)
{
	int		i;
	char	*str;

	str = ft_strdup(fmt->input);
	i = ++fmt->pos;
	while (ft_strchr(PLACEHOLDER_FLAGS, str[i]))
	{
		if (str[i] == '-')
			holder->flags |= FLAG_MINUS;
		else if (str[i] == '0')
			holder->flags |= FLAG_ZERO;
		else if (str[i] == '+')
			holder->flags |= FLAG_PLUS;
		else if (str[i] == '#')
			holder->flags |= FLAG_HASH;
		i++;
	}
	fmt->pos = i;
	free(str);
}

void	ft_parser_width(t_format *fmt, t_holder *holder)
{
	if (fmt->input[fmt->pos] == '*')
		holder->width = va_arg(fmt->args, int);
	else

		holder->width = ft_atoi(&fmt->input[fmt->pos]);
	while (ft_isdigit(fmt->input[fmt->pos]) || fmt->input[fmt->pos] == '*')
		fmt->pos++;
}

void	ft_parser_precision(t_format *fmt, t_holder *holder)
{
	if (fmt->input[fmt->pos] == '.')
	{
		fmt->pos++;
		if (fmt->input[fmt->pos] == '*')
			holder->width = va_arg(fmt->args, int);
		else
			holder->width = ft_atoi(&fmt->input[fmt->pos]);
		while (ft_isdigit(fmt->input[fmt->pos]) || fmt->input[fmt->pos] == '*')
			fmt->pos++;
	}
}

void	ft_parser_length(t_format *fmt, t_holder *holder)
{
	if (fmt->input[fmt->pos] == 'h')
	{
		holder->length |= L_SHORT;
		fmt->pos++;
		if (fmt->input[fmt->pos] == 'h')
		{
			holder->length |= L_CHAR;
			fmt->pos++;
		}
	}
	else if (fmt->input[fmt->pos] == 'l')
	{
		holder->length |= L_LONG;
		fmt->pos++;
		if (fmt->input[fmt->pos] == 'l')
		{
			holder->length |= L_LLONG;
			fmt->pos++;
		}
	}
}

void	ft_parser_conversion(t_format *fmt, t_holder *holder)
{
	int		i;
	int		len;
	char	*conversions;

	i = 0;
	len = ft_strlen(PLACEHOLDER_CONVERSIONS);
	conversions = ft_strdup(PLACEHOLDER_CONVERSIONS);
	while (i < len)
	{
		if (fmt->input[fmt->pos] == conversions[i])
			holder->conversion = conversions[i];
		i++;
	}
	free(conversions);
	fmt->pos++;
}
