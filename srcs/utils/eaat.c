/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/30 19:50:31 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (get_stop_flag(philo->table) == 0)
	{
		if (!get_stop_flag(philo->table) && !pthread_mutex_lock(philo->fork_r) && philo->fork_r_c == 0)
			{
				philo->fork_r_c = 1;
				if (print_status(philo->philo_id, FORK, philo->table) == 2)
					return (return_forks(philo), 2);
			}
		else
			return (return_forks(philo), 2);
		if (!get_stop_flag(philo->table) && !pthread_mutex_lock(philo->fork_l) && philo->fork_l_c == 0)
			{
				philo->fork_l_c = 1;
				if (print_status(philo->philo_id, FORK, philo->table) == 2)
					return (return_forks(philo), 2);
			}
		else
			return (return_forks(philo), 2);
	}
	return (0);
}

void	return_forks(t_philo *philo)
{
	if (philo->fork_l_c == 1)
	{
		pthread_mutex_unlock(philo->fork_l);
		philo->fork_l_c = 0;
	}
	if (philo->fork_r_c == 1)
	{
		pthread_mutex_unlock(philo->fork_r);
		philo->fork_r_c = 0;
	}
}

int	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->time);
	// philo->time_to_die = philo_get_time() + philo->table->time2die;
	pthread_mutex_unlock(&philo->time);
	if (print_status(philo->philo_id, EAT, philo->table) == 2)
		return (return_forks(philo), 2);
	ft_usleep(philo->table->time2eat);
	pthread_mutex_lock(&philo->eat_cont);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_cont);
	pthread_mutex_lock(&philo->time);
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	pthread_mutex_unlock(&philo->time);
	return_forks(philo);
	sleepin(philo);
	return (0);
}

int	think(t_philo *philo)
{
	if(print_status(philo->philo_id, THINK, philo->table) == 2)
		return (2);
	return (0);
}

int	sleepin(t_philo *philo)
{
	if (print_status(philo->philo_id, SLEEP, philo->table) == 2)
		return (2);
	ft_usleep(philo->table->time2sleep);
	return (0);
}
