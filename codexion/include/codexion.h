/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:49:16 by victode-          #+#    #+#             */
/*   Updated: 2026/11/05 19:14:00 by victode-         ###   ########.fr       */
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

/* * * * * * * * * * * * * * * * * * * */
/*           Scheduler data            */
/* * * * * * * * * * * * * * * * * * * */

typedef struct s_request
{
	long	request_time;
	long	deadline;
	int		sequence;

	t_coder	*coder;

}	t_request;

typedef struct s_heap
{
	int			size;
	int			capacity;

	t_request	*requests;

}	t_heap;

typedef enum e_request_status
{
	RS_IDLE,
	RS_WAITING,
	RS_GRANTED
}	t_request_status;

/* * * * * * * * * * * * * * * * * */
/*            Main data            */
/* * * * * * * * * * * * * * * * * */

typedef struct s_manager
{
	int				num_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	int				compiles_required;
	long			dongle_cooldown;
	int				scheduler;

	t_coder			*coders;
	t_dongle		*dongles;
	pthread_t		monitor;

	t_heap			heap;
	pthread_mutex_t	heap_mutex;
	pthread_cond_t	scheduler_cond;
	int				sequence;
	int				scheduler_cond_flag;
	int				heap_mutex_flag;

	long			start_time;

}	t_manager;

typedef struct s_coder
{
	int					id;
	int					compiles_done;
	long				last_compile_start;
	long				last_dongle_release;

	pthread_t			thread;
	t_dongle			*left_dongle;
	t_dongle			*right_dongle;
	t_manager			*data;
	t_request_status	request_status;

}	t_coder;

typedef struct s_dongle
{
	int				id;
	long			cooldown;
	int				in_use;
	long			available_at;

	pthread_mutex_t	mutex;

}	t_dongle;

/* = = = = = = = = Parser = = = = = = = = */
int			validate_args(int ac, char **av, int *result);
t_manager	*init_manager(int *data);

/* = = = = = = = = Utils = = = = = = = = */
void		clear_manager(t_manager *manager);
long		get_time(void);
long		get_current_time(t_manager *manager);

/* = = = = = = = = Scheduler = = = = = = = = */
void		heap_insert(int scheduler, t_heap *heap, t_request *request);
int			heap_pop(int scheduler, t_heap *heap, t_request *request);

#endif
