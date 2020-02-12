/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:39 by aroque            #+#    #+#             */
/*   Updated: 2020/02/12 11:03:05 by adrian           ###   ########.fr       */
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
	/* No placeholders */
	ft_printf_test("%05");
	ft_printf_test("%-05");
	ft_printf_test("%-5");
	ft_printf_test("Test - No Args\n");

	/* c conversion */
	ft_printf_test("%c\n", 'c');
	ft_printf_test("%5c\n", 'c');
	ft_printf_test("%-5c\n", 'c');
	ft_printf_test("%c\n", '\0');
	ft_printf_test("%5c\n", '\0');
	ft_printf_test("%-5c\n", '\0');
	ft_printf_test("%lc\n", 0xb1);

	/* pct conversion */
	ft_printf_test("%%\n");
	ft_printf_test("%8%\n");
	ft_printf_test("%-8%\n");
	ft_printf_test("%08%\n");
	ft_printf_test("%-08%\n");
	ft_printf_test("%%%%%%%%\n");
	ft_printf_test("%%%%%%%\n");

	/* p conversion */
	char a = 4;
	ft_printf_test("%p\n", &a);
	ft_printf_test("%.p\n", &a);
	ft_printf_test("%.5p\n", &a);
	ft_printf_test("%4p\n", &a);
	ft_printf_test("%20p\n", &a);
	ft_printf_test("%-20p\n", &a);
	ft_printf_test("%020p\n", &a);
	ft_printf_test("%p\n", NULL);
	ft_printf_test("%2p\n", NULL);
	ft_printf_test("%5p\n", NULL);
	ft_printf_test("%5.p\n", NULL);
	ft_printf_test("%2.9p\n", 1234);
	ft_printf_test("%9.2p\n", 1234);
	ft_printf_test("%%\n");
	ft_printf_test("Teste interessante\n");
	ft_printf_test("Teste %#00*.*d, esse é o teste %s\n", 10, 5, 42, "legal");
	ft_printf_test("Teste %0%\n");

	/* s conversion */
	ft_printf_test("%s\n", "string");
	ft_printf_test("%8s\n", "string");
	ft_printf_test("%8.3s\n", "string");
	ft_printf_test("%-8.3s\n", "string");
	ft_printf_test("%8.s\n", "string");
	ft_printf_test("%8.1s\n", "string");
	ft_printf_test("%-32s\n", "abc");
	ft_printf_test("%s\n", NULL);
	ft_printf_test("%.0s\n", NULL);
	ft_printf_test("%3.1s\n", NULL);
	ft_printf_test("%9.1s\n", NULL);
	ft_printf_test("%-32s\n", NULL);
	ft_printf_test("%-*.*s", -7, -3, "yolo");
	ft_printf_test("Test %s %s\n", "of", "string");

	/* u, x and X conversion */
	ft_printf_test("%u\n", 1);
	ft_printf_test("%4u\n", 1);
	ft_printf_test("%-4u\n", 1);
	ft_printf_test("%*.*u\n", 2, -1, 8);
	ft_printf_test("%*.*u\n", -1, 2, 8);
	ft_printf_test("%+#.5x\n", 0);
	ft_printf_test("%+#.5x\n", 312);
	ft_printf_test("%7X\n", 255);
	ft_printf_test("%#7X\n", 255);
	ft_printf_test("%-7X\n", 255);
	ft_printf_test("%-#7X\n", 255);
	ft_printf_test("%07x\n", 255);
	ft_printf_test("%0#7x\n", 255);
	ft_printf_test("%x\n", 0);
	ft_printf_test("%#x\n", 0);
	ft_printf_test("%x\n", 255);
	ft_printf_test("%#x\n", 255);
	ft_printf_test("%X\n", 255);
	ft_printf_test("%#X\n", 255);

	/* d and i conversions */
	ft_printf_test("%d\n", 0);
	ft_printf_test("%5d\n", 0);
	ft_printf_test("%5.3d\n", 0);
	ft_printf_test("%+.0d\n", 0);
	ft_printf_test("%+.5d\n", 0);
	ft_printf_test("%+5.3d\n", 0);
	ft_printf_test("%-+5.3d\n", 0);
	ft_printf_test("%-+05.3d\n", 0);
	ft_printf_test("%d\n", 1);
	ft_printf_test("%+d\n", 1);
	ft_printf_test("%d\n", -1);
	ft_printf_test("%5.4d\n", -1);
	ft_printf_test("% d\n", 42);
	ft_printf_test("%d\n", LONG_MAX);
	ft_printf_test("%ld\n", LONG_MAX);
	ft_printf_test("%lld\n", LLONG_MAX);
	ft_printf_test("%hd\n", LONG_MAX);
	ft_printf_test("%d\n", 1);
	ft_printf_test("%+d\n", 1);
	ft_printf_test("%10d\n", 1);
	ft_printf_test("%-10d\n", 1);
	ft_printf_test("%+10d\n", 1);
	ft_printf_test("%-+10d\n", 1);
	ft_printf_test("%04d\n", 5);
	ft_printf_test("%+d\n", 42);
	ft_printf_test("%+2d\n", 42);
	ft_printf_test("%+.1d\n", 42);
	ft_printf_test("%-*.*d\n", 3, 3, -12);
	ft_printf_test("%-0*i\n", 12, 8);
	ft_printf_test("%-*.*d", 3, 3, -12);
	ft_printf_test("%.*i", -6, -3);

	/* f conversions */
	//ft_printf("%f\n", 4.2);
	//ft_printf("%f\n", 4.29831);
	//printf("%10f\n", 4.2);
	//printf("%10.4f\n", 4.2);
	//printf("%010.4f\n", 4.2);
	//printf("%-10.4f\n", 4.2);
	//printf("%-010.4f\n", 4.2);
	//printf("%2.4f\n", 4.2);
	//printf("%02.4f\n", 4.2);
	//printf("%-2.4f\n", 4.2);
	//printf("%-02.4f\n", 4.2);
	//printf("%-02.1f\n", 4.2);
}
