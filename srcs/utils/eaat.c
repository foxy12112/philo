/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/05 16:34:48 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (philo->table->philo_amount == 1 && philo->table->dead == 0)
	{
		pthread_mutex_lock(philo->fork_r);
		print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		pthread_mutex_unlock(philo->fork_r);
		return (2);
	}
	else if (philo->table->dead == 0 && philo->table->philo_amount > 1)
	{
		if (!pthread_mutex_lock(philo->fork_r) && !philo->dead)
			print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		else
			return (pthread_mutex_unlock(philo->fork_r), 1);
		if (!pthread_mutex_lock(philo->fork_l) && !philo->dead)
			print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		else
			return (pthread_mutex_unlock(philo->fork_l), 1);
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

	if (philo->dead || philo->table->dead)
		return (1);
	foks = pick_forks(philo);
	if (foks == 0 && (philo->dead != 1 && philo->table->dead != 1))
	{
		pthread_mutex_lock(&philo->lock);
		philo->time_to_die = philo_get_time() + philo->table->time2die;
		philo->eating = 1;
		if (philo->dead == 1 || philo->table->dead == 1)
			return (pthread_mutex_unlock(&philo->lock), return_forks(philo), 1);
		print_status(tss(philo->table->start_time), philo->philo_id, EAT);
		philo->eat_count++;
		ft_usleep(philo->table->time2eat);
		philo->eating = 0;
		pthread_mutex_unlock(&philo->lock);
		return_forks(philo);
		if (philo->eat_count == philo->table->time2eat)
			return (0);
		sleepin(philo);
	}
	else if (foks == 2)
		ft_usleep(philo->table->time2die);
	return_forks(philo);
	return (0);
}

void	think(t_philo *philo)
{
	print_status(tss(philo->table->start_time), philo->philo_id, THINK);
}

void	sleepin(t_philo *philo)
{
	print_status(tss(philo->table->start_time), philo->philo_id, SLEEP);
	ft_usleep(philo->table->time2sleep);
}
