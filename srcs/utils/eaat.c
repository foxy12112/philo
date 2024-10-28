/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/10/28 13:46:50 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	print_status(tss(philo->table->start_time), philo->philo_id, FORK);
	pthread_mutex_lock(philo->fork_l);
	print_status(tss(philo->table->start_time), philo->philo_id, FORK);
}

static void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	eat(t_philo *philo)
{
	pick_forks(philo);
	print_status(tss(philo->table->start_time), philo->philo_id, EAT);
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	philo->eat_count++;
	ft_usleep(philo->table->time2eat);
	return_forks(philo);
	pthread_mutex_unlock(&philo->lock);
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
