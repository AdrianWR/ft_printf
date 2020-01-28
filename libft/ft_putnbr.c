/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:51:59 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 00:32:28 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(int n)
{
	unsigned int nb;
	size_t len;

	nb = 0;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putchar((nb % 10) + '0'));
	return (ft_putchar((nb % 10) + '0'));
	//return (len);
}
