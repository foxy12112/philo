/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/22 15:54:05 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (philo->table->dead == 0 && philo->table->philo_amount > 1 && philo->table->stup == 0)
	{
		if (!pthread_mutex_lock(philo->fork_r) && !philo->dead && !philo->table->stup)
			print_status(philo->philo_id, FORK, philo->table);
		else
			return (2);
		if (!pthread_mutex_lock(philo->fork_l) && !philo->dead && !philo->table->stup)
			print_status(philo->philo_id, FORK, philo->table);
		else
			return (2);
	}
	return (0);
}

static void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

int	eat(t_philo *philo)
{
	int	foks;

	if (philo->dead || philo->table->dead || philo->table->stup)
		return (2);
	foks = pick_forks(philo);
	if (foks == 0 && (philo->dead != 1 && philo->table->dead != 1))
	{
		pthread_mutex_lock(&philo->lock);
		philo->time_to_die = philo_get_time() + philo->table->time2die;
		philo->eating = 1;
		if (philo->dead == 1 || philo->table->dead == 1 || philo->table->stup)
			return (pthread_mutex_unlock(&philo->lock), return_forks(philo), 1);
		if (print_status(philo->philo_id, EAT, philo->table) == 2 || philo->table->stup)
			return (2);
		philo->eat_count++;
		ft_usleep(philo->table->time2eat);
		philo->eating = 0;
		pthread_mutex_unlock(&philo->lock);
		if (philo->eat_count == philo->table->time2eat)
			return (0);
	 	philo->time_to_die = philo_get_time() + philo->table->time2die;
	}
	if (philo->table->philo_amount > 1 && philo->table->stup == 0)
		return_forks(philo);
	if (foks == 2)
		return (2);
	sleepin(philo);
	return (0);
}

int	think(t_philo *philo)
{
	if(print_status(philo->philo_id, THINK, philo->table) == 2)
		return (2);
	return (0);
}

void	sleepin(t_philo *philo)
{
	print_status(philo->philo_id, SLEEP, philo->table);
	ft_usleep(philo->table->time2sleep);
}
