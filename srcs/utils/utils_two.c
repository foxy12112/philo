/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:35:08 by ldick             #+#    #+#             */
/*   Updated: 2024/12/02 23:44:59 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_end_one(t_table *table)
{
	pthread_mutex_destroy(&table->forks[0]);
	pthread_mutex_destroy(&table->stop);
	pthread_mutex_destroy(&table->time);
	pthread_mutex_destroy(&table->philo[0]->time);
	pthread_mutex_destroy(&table->philo[0]->eat_cont);
	pthread_mutex_destroy(&table->start);
	ft_freeall(table);
}

void	ft_set_flag(t_table *table)
{
	pthread_mutex_lock(&table->stop);
	table->stup = 1;
	pthread_mutex_unlock(&table->stop);
}
