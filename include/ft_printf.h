/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:47:31 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 15:23:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# define PLACEHOLDER_FLAGS "+-0#"
# define PLACEHOLDER_CONVERSIONS "cspdiuxX%"

typedef struct	s_holder
{
	int			width;
	int 		zero;
	int 		minus;
	int			plus;
	int			hash;
	int 		precision;
	char		conversion;
}				t_holder;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
size_t		ft_putaddress(void *p);
size_t		ft_puthex(unsigned int hex);
t_holder	*ft_parser(char **str);
size_t		ft_handler(t_holder *holder, va_list args);

#endif
