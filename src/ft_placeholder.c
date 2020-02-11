/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:46:45 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 00:16:58 by aroque           ###   ########.fr       */
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
