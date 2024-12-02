/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/12/02 23:42:20 by ldick            ###   ########.fr       */
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
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	lock;
	pthread_mutex_t	time;
	pthread_mutex_t	eat_cont;
	int				eat_count;
	int				sleeping;
	int				eating;
	int				start;
	int				importance;
	long			time_to_die;
	long			start_time;
	long			deb_time;
	int				dead;
	int				fork_l_c;
	int				fork_r_c;
}					t_philo;

//TODO NORM

typedef struct s_table
{
	pthread_t		*pid;
	long			time2die;
	pthread_mutex_t	stop;
	pthread_mutex_t	time;
	pthread_t		milk;
	pthread_t		deadwatch;
	int				stup;
	int				dead;
	long			time2eat;
	long			time2sleep;
	int				meals2eat;
	int				all_full;
	long			start_time;
	int				philo_amount;
	t_philo			**philo;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
}					t_table;

//			routine						//

int	think(t_philo *philo);
int		eat(t_philo *philo);
void	*philo_routine(void *philo_ptr);
int		sleepin(t_philo *philo);
void	one_philo(t_table *table);
void	*deadwatch(void *table_ptr);
void	*milk(void *philo_ptr);
void	*philo_one(void *philo_ptr);
void	return_forks(t_philo *philo);

//			init						//

int					init(int argc, char *argv[], t_table *table);

//			print						//

int				print_status(int id, char *status, t_table *table);

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
void				ft_set_flag(t_table *table)

//			Debug						//

void	debug(t_table *table);
void	log_philo_data(t_table *table);

#endif