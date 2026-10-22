/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:49:16 by victode-          #+#    #+#             */
/*   Updated: 2026/10/22 01:54:19 by victode-         ###   ########.fr       */
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

# define FIFO 1
# define EDF 0

typedef long long		t_ll;
typedef struct s_coder	t_coder;
typedef struct s_dongle	t_dongle;

/* =============== Data =============== */

typedef struct s_codexion
{
	int			num_coders;
	long		time_to_burnout;
	long		time_to_compile;
	long		time_to_debug;
	long		time_to_refactor;
	int			compiles_required;
	long		dongle_cooldown;
	int			scheduler;

	t_coder		*coders;
	t_dongle	*dongles;
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

typedef struct s_dongle
{
}	t_dongle;

/* =============== Parser =============== */

int	validate_args(int ac, char **av);

#endif
