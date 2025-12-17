/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:30:49 by victode-          #+#    #+#             */
/*   Updated: 2025/11/10 14:44:55 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int std_ret;
	int ft_ret;

	printf("\n1. Basic strings:\n");
	std_ret = printf("[Hello World!]\n");
	printf("printf: %d\n", std_ret);
	ft_ret = ft_printf("[Hello World!]\n");
	printf("ft_ret: %d\n\n", ft_ret);

	printf("\n2. Characters:\n");
	std_ret = printf("[%c]\n", 'A');
	ft_ret = ft_printf("[%c]\n", 'A');
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n3. Strings:\n");
	std_ret = printf("printf: [%s]\n", "%");
	ft_ret = ft_printf("ft_printf: [%s]\n", "%");
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	int x = 42;
	printf("\n4. Pointers:\n");
	std_ret = printf("printf: [%p]\n", &x);
	ft_ret = ft_printf("ft_printf: [%p]\n", &x);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n5. Integers (decimal):\n");
	std_ret = printf("printf: [%d]\n", 42);
	ft_ret = ft_printf("ft_printf: [%d]\n", 42);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n6. Negative integers:\n");
	std_ret = printf("printf: [%d]\n", -42);
	ft_ret = ft_printf("ft_printf: [%d]\n", -42);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n7. Unsigned integers:\n");
	std_ret = printf("printf: [%u]\n", 42);
	ft_ret = ft_printf("ft_printf: [%u]\n", 42);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n8. Hexadecimal (lowercase):\n");
	std_ret = printf("printf: [%x]\n", 42);
	ft_ret = ft_printf("ft_printf: [%x]\n", 42);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n9. Hexadecimal (uppercase):\n");
	std_ret = printf("printf: [%X]\n", 87);
	ft_ret = ft_printf("ft_printf: [%X]\n", 87);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n10. Percent sign:\n");
	std_ret = printf("printf: [%%]\n");
	ft_ret = ft_printf("ft_printf: [%%]\n");
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\n12. Edge cases:\n");

	char *s = NULL;
	printf("\nNULL string:\n");
	std_ret = printf("printf: [%s]\n", s);
	ft_ret = ft_printf("ft_printf: [%s]\n", s);
	printf("std_ret: %d, ft_ret: %d\n", std_ret, ft_ret);

	printf("\nInvalid specifier:\n");
	std_ret = printf("printf: [%/]\n", 42);
	ft_ret = ft_printf("ft_printf: [%/]\n", 42);
	printf("std_ret: %d, ft_ret: %d\n", std_ret, ft_ret);

	printf("\nINT_MAX:\n");
	std_ret = printf("printf: [%d]\n", INT_MAX);
	ft_ret = ft_printf("ft_printf: [%d]\n", INT_MAX);
	printf("std_ret: %d, ft_ret: %d\n", std_ret, ft_ret);

	printf("\nINT_MIN:\n");
	std_ret = printf("printf: [%d]\n", INT_MIN);
	ft_ret = ft_printf("ft_printf: [%d]\n", INT_MIN);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("\nNULL pointer:\n");
	std_ret = printf("printf: [%p]\n", NULL);
	ft_ret = ft_printf("ft_printf: [%p]\n", NULL);
	printf("std_ret: %d, ft_ret: %d\n\n", std_ret, ft_ret);

	printf("%d\n", printf(NULL));
	return (0);
}
