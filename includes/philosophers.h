/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/12/04 17:21:54 by ldick            ###   ########.fr       */
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

# define EAT "is eating"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define FORK "has taken a fork"
# define DEAD "died"

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		pid;
	int				philo_id;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	lock;
	pthread_mutex_t	time;
	pthread_mutex_t	eat_lock;
	int				eat_count;
	int				sleeping;
	int				eating;
	int				start;
	int				importance;
	long			time_to_die;
	long			start_time;
	int				dead;
	int				fork_left_flag;
	int				fork_right_flag;
}					t_philo;

// TODO NORM

typedef struct s_table
{
	pthread_t		*pid;
	long			death_time;
	pthread_mutex_t	stop;
	pthread_mutex_t	time;
	pthread_t		milk;
	pthread_t		deadwatch;
	int				stop_flag;
	int				dead;
	long			eat_time;
	long			sleep_time;
	int				food_amount;
	int				all_full;
	long			start_time;
	int				philo_amount;
	t_philo			**philo;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
}					t_table;

//			routine						//

int					think(t_philo *philo);
int					eat(t_philo *philo);
void				*philo_routine(void *philo_ptr);
int					sleepin(t_philo *philo);
void				one_philo(t_table *table);
void				*deadwatch(void *table_ptr);
void				*milk(void *philo_ptr);
void				*philo_one(void *philo_ptr);
void				return_forks(t_philo *philo);

//			init						//

int					init(int argc, char *argv[], t_table *table);

//			print						//

int					print_status(int id, char *status, t_table *table);

//			time functions				//

long				philo_get_time(void);
void				ft_usleep(long eepy_time);
long				tss(t_table *table);

//			utils						//

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					error_check(int argc, char *argv[]);
void				ft_end(t_table *table);
void				ft_end_one(t_table *table);
int					get_stop_flag(t_table *table);
void				ft_set_flag(t_table *table);
void				ft_freeall(t_table *table);
void				synchronize(t_table *table);
int					deadwatch_die(t_table *table, int i);

#endif

// 130 401 200 200 10 full fail
// 198 401 200 200 10 full fail 
// 198 405 200 200 10 20%correct
