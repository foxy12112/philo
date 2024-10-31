/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/10/31 12:45:28 by ldick            ###   ########.fr       */
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

# define EAT 1
# define THINK 2
# define SLEEP 3
# define FORK 4
# define DEAD 5

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
	int				importance;
	long			time_to_die;
	long			start_time;
	int				eating;
	int				dead;
}					t_philo;

typedef struct s_table
{
	pthread_t		*pid;
	long			time2die;
	int				dead;
	long			time2eat;
	long			time2sleep;
	int				meals2eat;
	long			start_time;
	unsigned int	philo_amount;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_table;

//			routine						//

void	think(t_philo *philo);
void	eat(t_philo *philo);
void	*philo_routine(void *philo_ptr);
void	sleepin(t_philo *philo);
void	one_philo(t_table *table);
void	eat_one(t_philo *philo);

//			init						//

int					init(int argc, char *argv[], t_table *table);

//			print						//

void	print_status(long time, int id, int status);

//			time functions				//

long				philo_get_time(void);
void				ft_usleep(long eepy_time);
long				tss(long start_time);

//			utils						//

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					error_check(int argc, char *argv[]);
void				ft_kill(t_table *table);

//			Debug						//

void	debug(int argc, char *argv[], t_table *table);

#endif