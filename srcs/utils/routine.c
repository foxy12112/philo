/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/10/31 14:06:58 by ldick            ###   ########.fr       */
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
	while (philo->dead == 0 || philo->eat_count != philo->table->meals2eat)
	{
		if (philo->time_to_die <= philo_get_time())
		{
			pthread_mutex_lock(&philo->lock);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->lock);
			print_status(tss(philo->start_time), philo->philo_id, DEAD);
			ft_kill(philo->table);
		}
		if (philo->eat_count == philo->table->meals2eat)
			printf("dis fucker is full\n");
		think(philo);
		eat(philo);
	}
	pthread_join(philo->pid, NULL);
	return (NULL);
}

// void	*deadwatch(void *table_ptr)
// {
// 	t_table *table;

// 	table = (t_table *)table_ptr;
	
// }