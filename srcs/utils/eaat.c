/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/25 19:33:08 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	return_forks(t_philo *philo);

static int	pick_forks(t_philo *philo)
{
	if (philo->table->dead == 0)
	{
		if (!philo->dead && !pthread_mutex_lock(philo->fork_r) && philo->fork_r_c == 0)
			{
				if (print_status(philo->philo_id, FORK, philo->table) == 2)
					return (2);
				philo->fork_r_c = 1;
			}
		else
			return (return_forks(philo), 2);
		if (!philo->dead && !pthread_mutex_lock(philo->fork_l) && philo->fork_l_c == 0)
			{
				if (print_status(philo->philo_id, FORK, philo->table) == 2)
					return (2);
				philo->fork_l_c = 1;
			}
		else
			return (return_forks(philo), 2);
	}
	return (0);
}

static void	return_forks(t_philo *philo)
{
	if (philo->fork_r_c == 1)
	{
		pthread_mutex_unlock(philo->fork_r);
		philo->fork_r_c = 0;
	}
	if (philo->fork_l_c == 1)
	{
		pthread_mutex_unlock(philo->fork_l);
		philo->fork_l_c = 0;
	}
}

int	eat(t_philo *philo)
{
	if (philo->dead || philo->table->dead)
		return (2);
	pick_forks(philo);
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	if (print_status(philo->philo_id, EAT, philo->table) == 2)
		return (return_forks(philo), 2);
	ft_usleep(philo->table->time2eat);
	philo->eat_count++;
	philo->time_to_die = philo_get_time() + philo->table->time2die;
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
