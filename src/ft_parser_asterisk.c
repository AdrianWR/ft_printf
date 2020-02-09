/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:51:16 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:51:29 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_asterisk(char option, t_format *f, t_holder *h)
{
	int spec;

	spec = va_arg(f->args, int);
	if (spec < 0)
	{
		if (!option)
		{
			spec *= -1;
			h->flags |= FLAG_MINUS;
		}
		else
			spec = -1;
	}
	return (spec);
}
