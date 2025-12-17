/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:36:40 by victode-          #+#    #+#             */
/*   Updated: 2025/11/10 17:24:52 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Writes a single character to the standard output.
 *
 * @param c The character to print.
 * @return The number of characters printed (always 1).
 */
int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

/**
 * @brief Writes a string to the standard output.
 *
 * If the string is NULL, it prints "(null)" instead.
 *
 * @param s The string to print.
 * @return The number of characters printed.
 */
int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (write (1, "(null)", 6));
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

/**
 * @brief Writes an integer (decimal base) to the standard output.
 *
 * Handles negative numbers correctly.
 *
 * @param nb The integer to print.
 * @return The number of characters printed.
 */
int	ft_putnbr(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

/**
 * @brief Writes an unsigned number in a given base to the standard output.
 *
 * The function recursively divides the number by the base length
 * and prints the corresponding digits.
 *
 * @param n The number to print.
 * @param base The string representing the base characters.
 * @param base_len The length of the base.
 * @return The number of characters printed.
 */
int	ft_putbase(t_ull n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (t_ull)base_len)
		count += ft_putbase(n / base_len, base, base_len);
	count += ft_putchar(base[n % base_len]);
	return (count);
}

/**
 * @brief Writes a memory address (pointer) to the standard output.
 *
 * Prints "(nil)" if the pointer is NULL. Otherwise prints in hexadecimal format.
 *
 * @param ptr The pointer to print.
 * @return The number of characters printed.
 */
int	ft_putptr(t_ull ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putbase(ptr, HEX, 16));
}
