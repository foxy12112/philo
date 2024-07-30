/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/07/30 13:21:29 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "libs.h"

# define PHILO_EAT "is eating"
# define PHILO_SLEEP "is sleeping"
# define PHILO_THINK "is thinking"
# define PHILO_TAKE "has taken a fork"
# define PHILO_DIE "died"

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}		t_opcode;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_philo
{	pthread_t			thread_id;
	int					id;
	int					eating;
	int					eals_meaten;
	bool				full;
	size_t				last_meal;
	int					*dead;
	t_fork				*r_fork;
	t_fork				*l_fork;
	pthread_mutex_t		*fork_lock;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
}			t_philo;

typedef struct s_table
{
	int					philo_nbr;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				nbr_limit_meals;
	size_t				start;
	size_t				cur_time;
	bool				end;
	t_fork				*forks;
	t_philo				*philo;
}				t_table;

void			error_exit(char *error);
void			parse(t_table *table, char *argv[]);
void			*safe_malloc(size_t bytes);
void			safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
int				philo_loop(t_table *table);
size_t		philo_get_time(void);
void			init(t_table *table);
void			print_timestamp(useconds_t timestamp, int philo_id, char *status);
void			*safe_malloc(size_t bytes);
void	time_since_start(t_table *table);
int	ft_usleep(size_t usec);



#endif