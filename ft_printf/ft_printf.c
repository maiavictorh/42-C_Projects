/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:41:34 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 17:38:51 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Checks if a character is a valid format specifier for ft_printf.
 *
 * Supported specifiers: c, s, p, d, i, u, x, X, %.
 *
 * @param c The character to check.
 * @return 1 if the character is a valid specifier, otherwise 0.
 */
static int	ft_is_spec(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

/**
 * @brief Prints the value corresponding to a format specifier.
 *
 * Handles each specifier by calling the appropriate helper function.
 *
 * Supported specifiers:
 *
 * c: character
 *
 * s: string
 *
 * p: pointer
 *
 * d/i: integer
 *
 * u: unsigned integer
 *
 * x/X: hexadecimal (lower/uppercase)
 *
 * %: percent sign
 *
 * @param c The format specifier character.
 * @param arg The list of variable arguments.
 * @return The number of characters printed.
 */
static int	ft_print_spec(int c, va_list *arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*arg, t_ull)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_putbase(va_arg(*arg, unsigned int), DEC, 10));
	else if (c == 'x')
		return (ft_putbase(va_arg(*arg, unsigned int), HEX, 16));
	else if (c == 'X')
		return (ft_putbase(va_arg(*arg, unsigned int), UPHEX, 16));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

/**
 * @brief Custom implementation of printf.
 *
 * Parses the format string and prints formatted output to the standard output.
 * Supports standard specifiers (c, s, p, d, i, u, x, X, %).
 *
 * @param format The string format.
 * @param ... The variable arguments to format and print.
 * @return The total number of characters printed.
 */
int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_spec(format[i + 1]))
				count += ft_print_spec(format[++i], &args);
			else if (!ft_is_spec(format[i + 1]))
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	printf("%d\n", printf("vic %", 10));
	ft_printf("%d\n", ft_printf("vic %", 10));
	printf("PRINTF:\n");
	printf("%d", printf(NULL));
	printf("\n");
	printf("%d", printf("var%d"));
	printf("\n");
	printf("%d", printf("var%w", 42));
	printf("\n");
	printf("%%");
	printf("\n\n");

	ft_printf("FT_PRINTF:\n");
	ft_printf("%d", ft_printf(NULL));
	ft_printf("\n");
	ft_printf("%d", ft_printf("var%d"));
	ft_printf("\n");
	ft_printf("%d", ft_printf("var%w", 42));
	ft_printf("\n");
	ft_printf("%%");
	ft_printf("\n");
	return (0);
}
*/