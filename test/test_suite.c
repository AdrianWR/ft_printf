/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:39 by aroque            #+#    #+#             */
/*   Updated: 2020/01/28 18:02:00 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

//static void	ft_printf_test(const char *format, ...)
//{
//	int ret;
//	int ret_ft;
//
//	va_list args;
//	va_list ft_args;
//	va_start(args, format);
//	va_copy(ft_args, args);
//	ret = vprintf(format, args);
//	va_end(args);
//	ret_ft = ft_vprintf(format, ft_args);
//	va_end(ft_args);
//	if (ret != ret_ft)
//		dprintf(2, "Error: ft_printf = %d; printf = %d\n", ret_ft, ret);
//}

int main(void)
{
	//(void) ft_printf_test;
	//ft_printf_test("Test - No Args\n");
	//ft_printf_test("Test %d\n", 2);
	//ft_printf_test("Teste %d %d %d\n", 3, 3, 3);
	//ft_printf_test("Teste 4\n");
	//ft_printf_test("Teste %d\n", 2048);
	//ft_printf_test("Teste %x\n", 2048);
	//ft_printf_test("Teste %d\n", 42);
	//ft_printf_test("Teste %-d\n", 42);
	//ft_printf_test("Teste %10d legal\n", 42);
	//ft_printf_test("Teste %-10d legal\n", 42);
	//ft_printf_test("Teste %+04d", 5);
	//ft_printf("%d\n", 2);
	//ft_printf("%d %d %d\n", 3, 3, 3);
	printf("Teste: %d\n", 1);
	printf("Teste: %10d\n", 1);
	printf("Teste: %-10d\n", 1);
	printf("Teste: %+10d\n", 1);
	printf("Teste: %-+10d\n", 1);
	printf("Teste: %+010d\n", 1);
}
