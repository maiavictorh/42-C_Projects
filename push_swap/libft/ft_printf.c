/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:05 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:14:05 by victode-         ###   ########.fr       */
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
