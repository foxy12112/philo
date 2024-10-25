/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/10/25 20:10:18 by ldick            ###   ########.fr       */
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
	int				philo_id;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*lock;
	int				eat_count;
	int				eating;
	int				sleeping;
	long			time_to_die;
}					t_philo;

typedef struct s_table
{
	pthread_t		*pid;
	long			time2die;
	long			time2eat;
	long			time2sleep;
	int				meals2eat;
	long			start_time;
	unsigned int	philo_amount;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_table;

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

#endif