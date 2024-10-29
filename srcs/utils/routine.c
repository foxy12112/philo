/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/10/29 11:14:38 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	table->start_time = philo_get_time();
	if (pthread_create(&table->pid[0], NULL,
			&philo_routine, &table->pid[0]))
		return ;
	pthread_detach(table->pid[0]);
	while (! table->dead)
		ft_usleep(0);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *) philo_ptr;
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	while (philo->time_to_die >= philo_get_time()
		|| philo->eat_count > philo->table->meals2eat)
	{
		think(philo);
		eat(philo);
	}
	return NULL;
}
