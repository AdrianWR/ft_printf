/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:40:51 by aroque            #+#    #+#             */
/*   Updated: 2020/02/11 18:22:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//static int	ft_pow(int base, unsigned int exp)
//{
//	if (!exp)
//		return (1);
//	return (base * ft_pow(base, exp - 1));
//}

//char	*ft_ftoa(float f)
//{
//	int		ipart;
//	float	fpart;
//
//	(void) ft_pow;
//	ipart = (int)f;
//	fpart = f - ipart; 
//	while (fpart - (float)ipart > 0.0)
//	{
//		fpart *= 10.0;
//	}
//	printf("real: %d\n", ipart);
//	printf("fraction: %f\n", fpart);
//	return (NULL);
//}

char			*ft_ftoa(float n)
{
	//char	*s;
	//size_t	len;
	//size_t	base_len;

	//if (ft_base_error(base))
	//	return (NULL);
	//base_len = ft_strlen(base);
	//len = ft_digit_counter(f, base_len);
	//if (!(s = malloc((len + 1) * sizeof(*s))))
	//	return (NULL);
	//s[len] = '\0';
	//while (len--)
	//{
	//	s[len] = base[n % base_len];
	//	n /= base_len;
	//}
	//return (s);
	(void) n;
	return (0);
}
