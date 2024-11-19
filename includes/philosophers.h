/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/11/19 16:53:56 by ldick            ###   ########.fr       */
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
	int				eat_count;
	int				sleeping;
	int				eating;
	int				start;
	int				importance;
	long			time_to_die;
	long			start_time;
	long			deb_time;
	int				dead;
}					t_philo;

typedef struct s_table
{
	pthread_t		*pid;
	long			time2die;
	pthread_mutex_t	stop;
	int				stup;
	int				dead;
	long			time2eat;
	long			time2sleep;
	int				meals2eat;
	int				all_full;
	long			start_time;
	int				philo_amount;
	pthread_mutex_t	spaek;
	t_philo			**philo;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
}					t_table;

//			routine						//

int	think(t_philo *philo);
int		eat(t_philo *philo);
void	*philo_routine(void *philo_ptr);
void	sleepin(t_philo *philo);
void	one_philo(t_table *table);
void	*deadwatch(void *table_ptr);
void	*milk(void *philo_ptr);

//			init						//

int					init(int argc, char *argv[], t_table *table);

//			print						//

int				print_status(long time, int id, char *status, t_table *table);

//			time functions				//

long				philo_get_time(void);
void				ft_usleep(long eepy_time);
long				tss(long start_time);

//			utils						//

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					error_check(int argc, char *argv[]);
void				ft_end(t_table *table);
void				ft_end_one(t_table *table);

//			Debug						//

void	debug(t_table *table);
void	log_philo_data(t_table *table);

#endif