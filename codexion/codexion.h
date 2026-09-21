/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:49:16 by victode-          #+#    #+#             */
/*   Updated: 2026/09/21 15:13:50 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

/* =============== Data =============== */

typedef struct s_codexion
{
}	t_codexion;

typedef struct s_coder
{
	int			id;
	pthread_t	thread;
	int			compiles_done;
	long		last_compile_start;
	long		last_dongle_release;
	t_codexion	*data;
}	t_coder;

/* =============== Parser =============== */
int	validate_number(const char *s, int *result);
int	parse_args(int ac, char **av);

#endif
