/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:35:08 by ldick             #+#    #+#             */
/*   Updated: 2024/12/03 20:30:10 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_end_one(t_table *table)
{
	pthread_mutex_destroy(&table->forks[0]);
	pthread_mutex_destroy(&table->stop);
	pthread_mutex_destroy(&table->time);
	pthread_mutex_destroy(&table->philo[0]->time);
	pthread_mutex_destroy(&table->philo[0]->eat_lock);
	pthread_mutex_destroy(&table->start);
	ft_freeall(table);
}

void	ft_set_flag(t_table *table)
{
	pthread_mutex_lock(&table->stop);
	table->stop_flag = 1;
	pthread_mutex_unlock(&table->stop);
}

void	synchronize(t_table *table)
{
	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
}

int	deadwatch_die(t_table *table, int i)
{
	pthread_mutex_lock(&table->stop);
	if (!table->stop_flag && philo_get_time() >= table->philo[i]->time_to_die)
	{
		printf("%lu %d %s\n", tss(table), i + 1, DEAD);
		table->stop_flag = 1;
		pthread_mutex_unlock(&table->philo[i]->time);
		return (pthread_mutex_unlock(&table->stop), 1);
	}
	return (0);
}
