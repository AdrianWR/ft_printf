/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:39 by aroque            #+#    #+#             */
/*   Updated: 2020/02/02 18:48:54 by aroque           ###   ########.fr       */
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
	void *p;
	char a;
	//short b;

	p = NULL;
	a = '4';
   	//b = 649999;
	(void) ft_printf_test;
	//ft_printf_test("Short %hd\n", b);
	//ft_printf("Short %hhd\n", 649999);
	//printf("Short %hhd\n", 649999);
	//ft_printf_test("Pointer %p\n", p);
	//ft_printf_test("Pointer %.p\n", p);
	//ft_printf_test("Pointer %p\n", &a);
	//ft_printf_test("Pointer %.3p\n", &a);
	//ft_printf_test("%5d\n", 231);
	//ft_printf_test("%-5d\n", 231);
	//ft_printf_test("%4.3d\n", 29);
	//ft_printf_test("%4.3d\n", 2890);
	//ft_printf_test("%s\n", "canino");
	//ft_printf_test("%8.3s\n", "canino");
	//ft_printf_test("%-8.3s\n", "canino");
	//ft_printf_test("%8.s\n", "string");
	//ft_printf_test("%8.1s\n", "string");
	//ft_printf_test("Teste %#00*.*d, esse é o teste %s\n", 10, 5, 42, "legal");
	//ft_printf("Teste %#00*.*d, esse é o teste %s\n", 10, 5, 42, "legal");
	//ft_printf_test("Teste %0%\n");
	//ft_printf_test("Numero decimal: %d\n", 1);
	//ft_printf_test("Numero decimal: %d\n", 42);
	//ft_printf_test("Numero hexadecimal: %x %%\n", 42);
	//ft_printf_test("Test - No Args\n");
	//ft_printf_test("Test %s %s\n", "de", "string");
	//ft_printf_test("Teste %d %d %d\n", 3, 3, 3);
	//ft_printf_test("Teste %4.2%\n");
	//ft_printf_test("Teste %d\n", 2048);
	//ft_printf_test("Teste %x\n", 255);
	//ft_printf_test("Teste %X\n", 255);
	//ft_printf_test("Teste %X\n", 255);
	//ft_printf_test("Teste %%\n");
	//ft_printf_test("Teste %%\n");
	//ft_printf_test("Teste %20s\n", "padding");
	//ft_printf_test("Teste %20x\n", 90);
	//ft_printf_test("Teste %4c\n", 'a');
	//ft_printf_test("Teste %4u\n", 23);
	//ft_printf_test("Teste %4u\n", -23);
	//ft_printf_test("Teste %5d\n", 20);
	//ft_printf_test("Teste %5.1d\n", 20);
	//ft_printf_test("Teste %-d\n", 42);
	//ft_printf_test("Teste %10d legal\n", 42);
	//ft_printf_test("Teste %-10d legal\n", 42);
	//ft_printf_test("Teste %-10s legal\n", "show");
	//ft_printf_test("Teste %04d\n", 5);
	//ft_printf_test("Teste %s\n", NULL);
	//ft_printf_test("Teste %%%%\n");
	//ft_printf_test("Teste %%%%\n");
	//ft_printf_test("%s%s", "Mais um ", "teste\n");
	//ft_printf_test("Teste short %hd\n", 12);
	//printf("Retorno: %d\n", printf("%s", NULL));
	//printf("Teste: %d\n", 1);
	//printf("Teste: %10d\n", 1);
	//printf("Teste: %-10d\n", 1);
	//printf("Teste: %+10d\n", 1);
	//printf("Teste: %-+10d\n", 1);
	ft_printf("%-32s\n", NULL);
	ft_printf("%-32s\n", "abc");
}