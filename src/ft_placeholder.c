/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:13:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:56:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_placeholder(int fd, t_format *fmt)
{
	t_holder	*h;

	h = ft_parser(fmt);
	if (h->conversion)
	{
		ft_replace(h, fmt->args);
		fmt->len += write(fd, h->replace, h->len);
		free(h->replace);
	}
	free(h);
}
