/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/10/30 17:01:14 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	table->philo[0].start_time = table->start_time;
	if (pthread_create(&table->pid[0], NULL, &philo_routine, &table->philo[0]))
		return ;
	pthread_detach(table->pid[0]);
	while (!table->philo[0].dead)
		ft_usleep(0);
	ft_kill(table);
	return ;
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	while (philo->dead == 0)
	{
		if (philo->time_to_die <= philo_get_time())
		{
			pthread_mutex_lock(&philo->lock);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->lock);
			print_status(tss(philo->start_time), philo->philo_id, DEAD);
		}
		if (philo->eat_count == philo->table->meals2eat)
			return (printf("dis fucker is full\n"), NULL);
		think(philo);
		eat(philo);
	}
	return (NULL);
}
