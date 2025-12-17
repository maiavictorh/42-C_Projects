/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:05 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:13:53 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putcharn(char c)
{
	return (write (1, &c, 1));
}

static int	ft_putstrn(char *s)
{
	if (!s)
		return (write (1, "(null)", 6));
	return (ft_putstr_fd(s, 1), ft_strlen(s));
}

static int	ft_putbase(t_ull n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (t_ull)base_len)
		count += ft_putbase(n / base_len, base, base_len);
	count += ft_putcharn(base[n % base_len]);
	return (count);
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
	t_ull	ptr;

	if (c == 'c')
		return (ft_putcharn(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstrn(va_arg(*arg, char *)));
	else if (c == 'p')
	{
		ptr = va_arg(*arg, t_ull);
		if (!ptr)
			return (ft_putstrn("(nil)"));
		return (ft_putstrn("0x") + ft_putbase(ptr, HEX, 16));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putstrn(ft_itoa(va_arg(*arg, int))));
	else if (c == 'u')
		return (ft_putbase(va_arg(*arg, t_ui), DEC, 10));
	else if (c == 'x')
		return (ft_putbase(va_arg(*arg, t_ui), HEX, 16));
	else if (c == 'X')
		return (ft_putbase(va_arg(*arg, t_ui), UPHEX, 16));
	else if (c == '%')
		return (ft_putcharn('%'));
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
			if (ft_strchr(SPEC, format[i + 1]))
				count += ft_print_spec(format[++i], &args);
			else if (!ft_strchr(SPEC, format[i + 1]))
				count += ft_putcharn('%');
		}
		else
			count += ft_putcharn(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/* int main(void)
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