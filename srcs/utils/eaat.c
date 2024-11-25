/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:34:59 by ldick             #+#    #+#             */
/*   Updated: 2024/11/25 13:57:14 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *philo)
{
	if (philo->table->dead == 0 && philo->table->philo_amount > 1 && philo->table->stup == 0)
	{
		if (!philo->dead && !philo->table->stup && !pthread_mutex_lock(philo->fork_r) && philo->fork_r_c == 0)
			{
				print_status(philo->philo_id, FORK, philo->table);
				philo->fork_r_c = 1;
			}
		else
			return (2);
		if (!philo->dead && !philo->table->stup && !pthread_mutex_lock(philo->fork_l) && philo->fork_l_c == 0)
			{
				print_status(philo->philo_id, FORK, philo->table);
				philo->fork_l_c = 1;
			}
		else
			return (pthread_mutex_unlock(philo->fork_r), philo->fork_r_c = 0, 2);
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
			return (pthread_mutex_unlock(&philo->lock), return_forks(philo), 2);
		if (print_status(philo->philo_id, EAT, philo->table) == 2 || philo->table->stup)
			return (2);
		ft_usleep(philo->table->time2eat);
		philo->eating = 0;
		pthread_mutex_unlock(&philo->lock);
		if (philo->table->all_full == philo->table->meals2eat)
			return (2);
	 	philo->time_to_die = philo_get_time() + philo->table->time2die;
	}
	if (philo->table->philo_amount > 1 && philo->table->stup == 0)
		return_forks(philo);
	sleepin(philo);
	philo->eat_count++;
	if (foks == 2 || philo->table->stup == 1)
		return (2);
	return (0);
}

int	think(t_philo *philo)
{
	if(philo->table->stup == 1 || print_status(philo->philo_id, THINK, philo->table) == 2)
		return (2);
	return (0);
}

void	sleepin(t_philo *philo)
{
	print_status(philo->philo_id, SLEEP, philo->table);
	ft_usleep(philo->table->time2sleep);
}
