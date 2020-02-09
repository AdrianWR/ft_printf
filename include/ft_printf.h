/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:47:31 by aroque            #+#    #+#             */
/*   Updated: 2020/02/08 23:58:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

# define PLACEHOLDER_FLAGS			"+-0#"
# define PLACEHOLDER_CONVERSIONS	"cspdiuxX%"

# define WIDTH 0
# define PRECISION 1

# define FLAG_MINUS	0b0001
# define FLAG_PLUS	0b0010
# define FLAG_ZERO 	0b0100
# define FLAG_HASH 	0b1000

# define	L_SHORT	0b0001
# define	L_CHAR	0b0011
# define	L_LONG	0b0010
# define	L_LLONG	0b0110

# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"

# define STR_NULL	"(null)"
# define STR_EMPTY	""
# define PTR_START	"0x"

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
	const char	*input;
	va_list		args;
	int			pos;
	int			len;
}				t_format;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_parser_asterisk(char option, t_format *f, t_holder *h);
void		ft_parser_flags(t_format *fmt, t_holder *holder);
void		ft_parser_width(t_format *fmt, t_holder *holder);
void		ft_parser_precision(t_format *fmt, t_holder *holder);
void		ft_parser_length(t_format *fmt, t_holder *holder);
void		ft_parser_conversion(t_format *fmt, t_holder *holder);
void		ft_parser_dump(t_holder *holder);
void		ft_placeholder(int fd, t_format *fmt);
void		ft_replace(t_holder *h, va_list args);
char		*ft_itoa_base(int n, const char *base);
char		*ft_itoa_ubase(long unsigned int n, const char *base);
char		*ft_handle_p(t_holder *h, va_list args);
char		*ft_handle_d(t_holder *h, va_list args);
char		*ft_handle_ux(t_holder *h, va_list args, char *base);
char		*ft_handle_s(t_holder *h, va_list args);
char		*ft_handle_c(t_holder *h, va_list args);
char		*ft_handle_pct(t_holder *h);
char		*ft_pad_left(char *src, char pad, int width);
char		*ft_pad_right(char *src, char pad, int width);
t_holder	*ft_parser(t_format *fmt);
t_format	*ft_format_initializer(const char *format, va_list args);

#endif
