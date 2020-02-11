/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:12:14 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 14:36:01 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conversion_f(t_holder *h, va_list args)
{
	(void) h;
	(void) args;
	ft_ftoa(va_arg(args, double));
}
