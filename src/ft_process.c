/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:13:48 by aroque            #+#    #+#             */
/*   Updated: 2020/02/03 23:19:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	ft_pre_output(t_format *fmt)
{
	char	*tmp;
	char	*substr;

	tmp = ft_strdup(fmt->output);
	substr = ft_substr(fmt->input, fmt->start, fmt->pos - fmt->start);
	free(fmt->output);
	fmt->output = ft_strjoin(tmp, substr);
	free(tmp);
	free(substr);
}

static void	ft_holder_replace(t_holder *holder, va_list args)
{
	ft_replace_conversion(holder, args);
	//ft_replace_precision(holder);
	//ft_replace_width(holder);
}

static void	ft_join_replace(t_format *fmt, t_holder *holder)
{
	char	*tmp;

	tmp = ft_strdup(fmt->output);
	free(fmt->output);
	fmt->output	= ft_strjoin(tmp, holder->replace);
	fmt->start = fmt->pos + 1;
	free(tmp);
}

void	ft_process(t_format *fmt)
{
	t_holder	*holder;

	ft_pre_output(fmt);
	holder = ft_parser(fmt);
	ft_holder_replace(holder, fmt->args);
	ft_join_replace(fmt, holder);
	free(holder->replace);
	free(holder);
}
