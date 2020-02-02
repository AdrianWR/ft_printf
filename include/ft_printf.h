/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:47:31 by aroque            #+#    #+#             */
/*   Updated: 2020/02/02 16:55:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define PLACEHOLDER_FLAGS			"+-0#"
# define PLACEHOLDER_CONVERSIONS	"cspdiuxX%"

# define	FLAG_MINUS	0b0001
# define	FLAG_PLUS	0b0010
# define	FLAG_ZERO 	0b0100
# define	FLAG_HASH 	0b1000

# define	L_SHORT	0b0001
# define	L_CHAR	0b0011
# define	L_LONG	0b0010
# define	L_LLONG	0b0110

# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"

typedef struct	s_holder
{
	char		flags;
	int			width;
	int 		precision;
	char		length;
	char		conversion;
	char		*replace;
	size_t		len;
}				t_holder;

typedef struct	s_format
{
	char		*input;
	char		*output;
	va_list		args;
	size_t		start;
	size_t		pos;
	size_t		len;
}				t_format;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
void		ft_parser_flags(t_format *fmt, t_holder *holder);
void		ft_parser_width(t_format *fmt, t_holder *holder);
void		ft_parser_precision(t_format *fmt, t_holder *holder);
void		ft_parser_length(t_format *fmt, t_holder *holder);
void		ft_parser_conversion(t_format *fmt, t_holder *holder);
void		ft_pre_output(t_format *fmt);
void		ft_process(t_format *fmt);
void		ft_replace_conversion(t_holder *h, va_list args);
void		ft_replace_width(t_holder *h);
void		ft_replace_precision(t_holder *h);
char		*ft_itoa_base(int n, const char *base);
char		*ft_itoa_ubase(long long unsigned int n, const char *base);
char		*ft_pointerdup(void *p);
char		*ft_handle_d(t_holder *h, va_list args);
char		*ft_handle_s(char *str);
size_t		ft_abs(int n);
t_holder	*ft_parser(t_format *fmt);

#endif
