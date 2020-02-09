/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:06:14 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:57:55 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base_error(const char *base)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(base);
	if (len < 2)
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

static size_t	ft_digit_counter(int n, int base_len)
{
	if (!(n / base_len))
		return (1);
	else
		return (ft_digit_counter(n / base_len, base_len) + 1);
}

static size_t	ft_abs(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	else
		return ((unsigned int)n);
}

/*
**	Convert an int to its string representation,
** accordingly to an input base. The base must be
** passed as a string of all base digits, in order.
** For example, the decimal base would be "0123456789".
*/

char			*ft_itoa_base(int n, const char *base)
{
	char	*s;
	size_t	len;
	size_t	nbr;
	int		base_len;

	if (ft_base_error(base))
		return (NULL);
	base_len = (int)ft_strlen(base);
	len = ft_digit_counter(n, base_len);
	n < 0 ? len++ : len;
	nbr = ft_abs(n);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
