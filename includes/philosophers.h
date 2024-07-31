/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:07 by ldick             #+#    #+#             */
/*   Updated: 2024/07/31 15:05:03 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libs.h"
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

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef struct s_time
{
	useconds_t			current_time;
	useconds_t			start_time;
	useconds_t			time_to_die;
	useconds_t			time_to_eat;
	useconds_t			time_to_sleep;
}						t_time;

typedef struct s_philo_data
{
	long				philo_nbr;
	long				meals_amount;
	int					meals_eaten;
	bool				dead;
	bool				full;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*eat_count_lock;
}						t_philo_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		last_meal_lock;
	pthread_mutex_t		*fork_lock;
	useconds_t			last_meal;
	struct s_philo_data	*data;
	struct s_time		*time;
}						t_philo;

//			init						//

void					init(char *argv[], t_philo *philo);

//			time functions				//

useconds_t				philo_get_time(void);

#endif