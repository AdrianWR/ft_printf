/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 02:17:06 by aroque            #+#    #+#             */
/*   Updated: 2020/02/10 14:23:06 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check for errors in base description,
** such as repeated characters or less than
** two digits in its representation
*/

static int		ft_base_error(const char *base)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(base);
	if (len <= 1)
		return (1);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	ft_digit_counter(uintmax_t n, size_t base_len)
{
	if (!(n / base_len))
		return (1);
	else
		return (ft_digit_counter(n / base_len, base_len) + 1);
}

/*
**	Convert an int to its string representation,
** accordingly to an input base. The base must be
** passed as a string of all base digits, in order.
** For example, the decimal base would be "0123456789".
*/

char			*ft_uitoa_base(uintmax_t n, const char *base)
{
	char	*s;
	size_t	len;
	size_t	base_len;

	if (ft_base_error(base))
		return (NULL);
	base_len = ft_strlen(base);
	len = ft_digit_counter(n, base_len);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = base[n % base_len];
		n /= base_len;
	}
	return (s);
}
