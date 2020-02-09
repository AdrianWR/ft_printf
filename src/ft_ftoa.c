/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:40:51 by aroque            #+#    #+#             */
/*   Updated: 2020/02/09 06:49:49 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_pow(int base, unsigned int exp)
{
	if (!exp)
		return (1);
	return (base * ft_pow(base, exp - 1));
}

char	*ft_ftoa(float f)
{
	int		ipart;
	float	fpart;

	(void) ft_pow;
	ipart = (int)f;
	fpart = f - ipart; 
	while ((fpart - ipart) > 0)
	{
		fpart *= 10;
	}
	printf("real: %d\n", ipart);
	printf("fraction: %f\n", fpart);
	return (NULL);
}
