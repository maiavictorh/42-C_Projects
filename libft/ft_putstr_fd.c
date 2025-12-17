/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:05:14 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:50:52 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Writes a string to the given file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write (fd, s++, 1);
}
/*
int main(void)
{
	ft_putstr_fd("Hello World!\n", 1);
}
*/