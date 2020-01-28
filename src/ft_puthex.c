/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:20:33 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 00:06:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	ft_charhex(unsigned int hex)
{
	if (hex < 10)
		return (hex + '0');
	if (hex < 16)
		return (hex - 10 + 'a');
	return (0);
}

size_t	ft_puthex(unsigned int hex)
{
	if (hex >= 16)
		return (ft_puthex(hex / 16) + ft_putchar(ft_charhex((hex % 16))));
	return (ft_putchar(ft_charhex(hex % 16)));
}
