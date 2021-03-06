/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:15:20 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 15:04:33 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_flags(t_format *f, t_holder *holder)
{
	if (!f->input[f->pos])
		return ;
	while (ft_strchr(PLACEHOLDER_FLAGS, f->input[f->pos]))
	{
		if (f->input[f->pos] == '-')
			holder->flags |= FLAG_MINUS;
		else if (f->input[f->pos] == '0')
			holder->flags |= FLAG_ZERO;
		else if (f->input[f->pos] == '+')
			holder->flags |= FLAG_PLUS;
		else if (f->input[f->pos] == '#')
			holder->flags |= FLAG_HASH;
		else if (f->input[f->pos] == ' ')
			holder->flags |= FLAG_SPACE;
		f->pos++;
	}
}

void	ft_parser_width(t_format *f, t_holder *h)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == '*')
	{
		h->width = ft_parser_star(WIDTH, f, h);
		f->pos++;
	}
	else
	{
		h->width = ft_atoi(f->input + f->pos);
		while (ft_isdigit(f->input[f->pos]))
			f->pos++;
	}
}

void	ft_parser_precision(t_format *f, t_holder *h)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == '.')
	{
		f->pos++;
		if (f->input[f->pos] == '*')
		{
			h->precision = ft_parser_star(PRECISION, f, h);
			f->pos++;
		}
		else
		{
			if (!ft_isdigit(f->input[f->pos]))
				h->precision = 0;
			else
				h->precision = ft_atoi(f->input + f->pos);
			while (ft_isdigit(f->input[f->pos]))
				f->pos++;
		}
	}
}

void	ft_parser_length(t_format *f, t_holder *holder)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == 'h')
	{
		holder->length |= L_SHORT;
		f->pos++;
		if (f->input[f->pos] == 'h')
		{
			holder->length |= L_CHAR;
			f->pos++;
		}
	}
	else if (f->input[f->pos] == 'l')
	{
		holder->length |= L_LONG;
		f->pos++;
		if (f->input[f->pos] == 'l')
		{
			holder->length |= L_LLONG;
			f->pos++;
		}
	}
}

void	ft_parser_conversion(t_format *f, t_holder *holder)
{
	int		i;
	int		len;
	char	*conversions;

	if (!f->input[f->pos])
		return ;
	i = 0;
	len = ft_strlen(PLACEHOLDER_CONVERSIONS);
	conversions = ft_strdup(PLACEHOLDER_CONVERSIONS);
	while (i < len)
	{
		if (f->input[f->pos] == conversions[i])
			holder->conversion = conversions[i];
		i++;
	}
	free(conversions);
	f->pos++;
}
