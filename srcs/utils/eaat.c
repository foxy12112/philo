/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/12/04 17:56:22 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->fork_right)
		&& philo->fork_right_flag == 0)
	{
		philo->fork_right_flag = 1;
		if (print_status(philo->philo_id, FORK, philo->table) == 2)
			return (return_forks(philo), 2);
	}
	else
		return (return_forks(philo), 2);
	if (!pthread_mutex_lock(philo->fork_left) && philo->fork_left_flag == 0)
	{
		philo->fork_left_flag = 1;
		if (print_status(philo->philo_id, FORK, philo->table) == 2)
			return (return_forks(philo), 2);
	}
	else
		return (return_forks(philo), 2);
	return (0);
}

void	return_forks(t_philo *philo)
{
	if (philo->fork_left_flag == 1)
	{
		pthread_mutex_unlock(philo->fork_left);
		philo->fork_left_flag = 0;
	}
	if (philo->fork_right_flag == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		philo->fork_right_flag = 0;
	}
}

int	eat(t_philo *philo)
{
	pick_forks(philo);
	if (print_status(philo->philo_id, EAT, philo->table) == 2)
		return (return_forks(philo), 2);
	ft_usleep(philo->table->eat_time);
	pthread_mutex_lock(&philo->eat_lock);
	pthread_mutex_lock(&philo->time);
	philo->time_to_die = philo_get_time() + philo->table->death_time;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_lock);
	pthread_mutex_unlock(&philo->time);
	return_forks(philo);
	sleepin(philo);
	return (0);
}

int	think(t_philo *philo)
{
	if (print_status(philo->philo_id, THINK, philo->table) == 2)
		return (2);
	return (0);
}

int	sleepin(t_philo *philo)
{
	if (print_status(philo->philo_id, SLEEP, philo->table) == 2)
		return (2);
	ft_usleep(philo->table->sleep_time);
	return (0);
}
