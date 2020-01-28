/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemoryaddress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:35:15 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 01:49:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putaddress(void *ptr)
{
	unsigned int p;
   
	p = (unsigned int)ptr;
	return (ft_putnbr(p));
}
