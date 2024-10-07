/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/10/07 16:11:52 by ldick            ###   ########.fr       */
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

# define PHILO_EAT "is eating"
# define PHILO_SLEEP "is sleeping"
# define PHILO_THINK "is thinking"
# define PHILO_TAKE "has taken a fork"
# define PHILO_DIE "died"

typedef enum e_errcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_errcode;

typedef struct s_time
{
	long	current_time;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
}			t_time;

typedef struct s_philo
{
	int		philo_id;
	int		fork_l;
	int		fork_r;
	int		meals_eaten;
	bool	full;
	bool	dead;
	int		philo_nbr;
	int		meals_till_full;
}			t_philo;

//			init						//

int			parse(char *argv[], t_philo *philo);
t_philo		init(char *argv[], t_philo *philo, t_time *time);

//			time functions				//

long		philo_get_time(void);
long		philo_time_since_start(long start_time);
int			ft_usleep(long time);

//			utils						//

int			ft_atoi(char *str);

#endif