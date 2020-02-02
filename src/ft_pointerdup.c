/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:14:40 by aroque            #+#    #+#             */
/*   Updated: 2020/02/02 17:19:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_pointerdup(void *p)
{
	char	*dup;
	char	*ptr;

	if (!(dup = ft_calloc(sizeof(p), sizeof(unsigned char))))
		return (NULL);
	dup[0] = '0';
	dup[1] = 'x';
	ptr = ft_itoa_ubase((long unsigned int)p, HEX_BASE_L);
	ft_strlcat(dup, ptr,  2 * sizeof(p) - 1);
	free(ptr);
	return (dup);
}
