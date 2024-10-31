/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/10/31 14:05:41 by ldick            ###   ########.fr       */
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
		pthread_mutex_lock(philo->fork_r);
		print_status(tss(philo->table->start_time), philo->philo_id, FORK);
		pthread_mutex_lock(philo->fork_l);
		print_status(tss(philo->table->start_time), philo->philo_id, FORK);
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
	if (pick_forks(philo) == 2)
		return ;
	pick_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	print_status(tss(philo->table->start_time), philo->philo_id, EAT);
	philo->eat_count++;
	ft_usleep(philo->table->time2eat);
	pthread_mutex_unlock(&philo->lock);
	return_forks(philo);
	sleepin(philo);
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
