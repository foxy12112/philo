/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/03 17:22:07 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (philo->table->philo_amount == 1)
	{
		pthread_mutex_lock(philo->fork_r);
		print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		pthread_mutex_unlock(philo->fork_r);
		return (2);
	}
	else
	{
		if (!pthread_mutex_lock(philo->fork_r))
			print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		else
			pthread_mutex_unlock(philo->fork_r);
		if (!pthread_mutex_lock(philo->fork_l))
			print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		else
			pthread_mutex_unlock(philo->fork_l);
	}
	return (0);
}

static void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	eat(t_philo *philo)
{
	int	foks;

	foks = pick_forks(philo);
	if (foks == 0 || philo->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		philo->time_to_die = philo_get_time() + philo->table->time2die;
		print_status(tss(philo->table->start_time), philo->philo_id, EAT);
		philo->eat_count++;
		ft_usleep(philo->table->time2eat);
		pthread_mutex_unlock(&philo->lock);
		return_forks(philo);
		if (philo->eat_count == philo->table->time2eat)
			return ;
		sleepin(philo);
	}
	else if (foks == 2)
		ft_usleep(philo->table->time2die);
	return_forks(philo);
	return ;
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
