/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:47:31 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 19:43:00 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

# define PLACEHOLDER_FLAGS			"+- 0#"
# define PLACEHOLDER_CONVERSIONS	"cspdiuxX%"

# define MINUS		'-'
# define PLUS		'+'
# define SPACE		' '
# define ZERO		'0'
# define X			'x'

# define WIDTH		0
# define PRECISION	1

# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_ZERO 	4
# define FLAG_HASH 	8
# define FLAG_SPACE	16

# define L_CHAR		1
# define L_SHORT	2
# define L_LONG		4
# define L_LLONG	8

# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"
# define OCT_BASE	"01234567"

# define STR_NULL	"(null)"
# define STR_EMPTY	""
# define PTR_START	"0x"

typedef struct	s_holder
{
	char		flags;
	int			width;
	int			precision;
	char		length;
	char		conversion;
	char		prefix;
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

/*
** ------------------------------
** --- Printf Function Family ---
** ------------------------------
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

/*
**	------------------------
**	--- Parser Functions ---
**	------------------------
*/

t_holder		*ft_holder_initializer(void);
t_holder		*ft_parser(t_format *f);
int				ft_parser_star(char option, t_format *f, t_holder *h);
void			ft_parser_flags(t_format *f, t_holder *h);
void			ft_parser_width(t_format *f, t_holder *h);
void			ft_parser_precision(t_format *f, t_holder *h);
void			ft_parser_length(t_format *f, t_holder *h);
void			ft_parser_conversion(t_format *f, t_holder *h);
void			ft_parser_dump(t_holder *h);

/*
** ----------------------------
** --- Conversion Functions ---
** ----------------------------
*/

void			ft_conversion_pct(t_holder *h);
void			ft_conversion_p(t_holder *h, va_list args);
void			ft_conversion_d(t_holder *h, va_list args);
void			ft_conversion_s(t_holder *h, va_list args);
void			ft_conversion_c(t_holder *h, va_list args);
void			ft_conversion_ux(t_holder *h, va_list args, const char *base);

/*
** -----------------------
** --- Other Functions ---
** -----------------------
*/

t_format		*ft_format_initializer(const char *format, va_list args);
void			ft_placeholder(int fd, t_format *fmt);
void			ft_replace(t_holder *h, va_list args);
void			ft_pad_left(char **src, char pad, int width);
void			ft_pad_right(char **src, char pad, int width);
void			ft_prefix(t_holder *h);
char			*ft_uitoa_base(uintmax_t n, const char *base);

/*
**	░░░░░░░█▐▓▓░████▄▄▄█▀▄▓▓▓▌█
**	░░░░░▄█▌▀▄▓▓▄▄▄▄▀▀▀▄▓▓▓▓▓▌█
**	░░░▄█▀▀▄▓█▓▓▓▓▓▓▓▓▓▓▓▓▀░▓▌█
**	░░█▀▄▓▓▓███▓▓▓███▓▓▓▄░░▄▓▐█▌
**	░█▌▓▓▓▀▀▓▓▓▓███▓▓▓▓▓▓▓▄▀▓▓▐█
**	▐█▐██▐░▄▓▓▓▓▓▀▄░▀▓▓▓▓▓▓▓▓▓▌█▌
**	█▌███▓▓▓▓▓▓▓▓▐░░▄▓▓███▓▓▓▄▀▐█
**	█▐█▓▀░░▀▓▓▓▓▓▓▓▓▓██████▓▓▓▓▐█
**	▌▓▄▌▀░▀░▐▀█▄▓▓██████████▓▓▓▌█▌
**	▌▓▓▓▄▄▀▀▓▓▓▀▓▓▓▓▓▓▓▓█▓█▓█▓▓▌█▌
**	█▐▓▓▓▓▓▓▄▄▄▓▓▓▓▓▓█▓█▓█▓█▓▓▓▐█
*/

#endif
