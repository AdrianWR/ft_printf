/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:39 by aroque            #+#    #+#             */
/*   Updated: 2020/02/01 01:50:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

static void	ft_printf_test(const char *format, ...)
{
	int ret;
	int ret_ft;

	va_list args;
	va_list ft_args;
	va_start(args, format);
	va_copy(ft_args, args);
	ret = vprintf(format, args);
	va_end(args);
	ret_ft = ft_vprintf(format, ft_args);
	va_end(ft_args);
	if (ret != ret_ft)
		dprintf(2, "Error: ft_printf = %d; printf = %d\n", ret_ft, ret);
}

int main(void)
{
	//ft_printf("Teste %#++00*.*hhd, esse é o teste %lls\n", 10, 5, 42, "legal");
	//ft_printf("Teste %0%\n");
	//printf("Teste %0%\n");
	//printf("Teste %5%\n");
	//ft_printf("Numero decimal: %d\n", 1);
	//ft_printf("Numero decimal: %d\n", 42);
	//ft_printf("Numero hexadecimal: %x %%\n", 42);
	//ft_printf("Retorno: %d\n", k);
	ft_printf_test("Test - No Args\n");
	ft_printf_test("Test %s %s\n", "de", "string");
	ft_printf_test("Teste %d %d %d\n", 3, 3, 3);
	ft_printf_test("Teste 4\n");
	ft_printf_test("Teste %d\n", 2048);
	ft_printf_test("Teste %x\n", 255);
	ft_printf_test("Teste %X\n", 255);
	ft_printf_test("Teste %X\n", 255);
	ft_printf_test("Teste %%\n");
	ft_printf_test("Teste %%\n");
	ft_printf_test("Teste %20s\n", "padding");
	ft_printf_test("Teste %20x\n", 90);
	ft_printf_test("Teste %4c\n", 'a');
	//ft_printf_test("Teste %-d\n", 42);
	//ft_printf_test("Teste %10d legal\n", 42);
	//ft_printf_test("Teste %-10d legal\n", 42);
	//ft_printf_test("Teste %+04d", 5);
	//ft_printf("%d\n", 2);
	//ft_printf("%d %d %d\n", 3, 3, 3);
	//printf("Teste: %d\n", 1);
	//printf("Teste: %10d\n", 1);
	//printf("Teste: %-10d\n", 1);
	//printf("Teste: %+10d\n", 1);
	//printf("Teste: %-+10d\n", 1);
	//printf("Teste: %+010d\n", 1);
}
