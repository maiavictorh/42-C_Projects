/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:49:16 by victode-          #+#    #+#             */
/*   Updated: 2026/11/20 13:18:24 by victode-         ###   ########.fr       */
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
	pthread_mutex_t	mutex;

	t_heap			heap;
	int				sequence;

	long			start_time;
	int				running;

}	t_manager;

typedef struct s_coder
{
	int					id;
	int					compiles_done;
	long				last_compile_start;

	pthread_t			thread;
	t_dongle			*left_dongle;
	t_dongle			*right_dongle;
	t_manager			*manager;

}	t_coder;

typedef struct s_dongle
{
	int				id;
	int				in_use;
	long			available_at;

}	t_dongle;

/* = = = = = = = = Parser = = = = = = = = */
int			validate_args(int ac, char **av, int *result);
t_manager	*init_manager(int *data);

/* = = = = = = = = Main = = = = = = = = */

void		*monitor_routine(void *arg);
int			run(t_manager *manager);

/* = = = = = = = = Utils = = = = = = = = */
void		clear_manager(t_manager *manager);
void		abort_run(t_manager *manager, int created);
long		get_time(void);
long		get_elapsed_time(t_manager *manager);
void		log_message(t_coder *coder, char *message);
int			is_running(t_manager *manager);

/* = = = = = = = = Coder = = = = = = = = */
int			compile(t_coder *coder);
int			debug(t_coder *coder);
int			refactor(t_coder *coder);
void		*coder_routine(void *arg);

/* = = = = = = = = Heap = = = = = = = = */
void		swap_requests(t_request *request_1, t_request *request_2);
int			is_dongle_available(t_request *request, long current_time);
int			create_request(t_coder *coder);
int			get_best_request(t_manager *manager);
void		restore_priority(int scheduler, int index, t_heap *heap);
int			compare_requests(int scheduler,
				t_request *request_1, t_request *request_2);
int			heap_insert(int scheduler, t_heap *heap, t_request *request);
int			heap_remove(int scheduler, t_heap *heap, int index);

#endif
