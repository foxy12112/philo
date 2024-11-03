/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/11/03 17:44:25 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	table->philo[0]->start_time = table->start_time;
	if (pthread_create(&table->pid[0], NULL, &philo_routine, table->philo[0]))
		return ;
	pthread_detach(table->pid[0]);
	while (!table->philo[0]->dead)
		ft_usleep(0);
	pthread_mutex_destroy(&table->philo[0]->lock);
	pthread_mutex_destroy(table->philo[0]->fork_r);
	return ;
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	if (pthread_create(&philo->pid, NULL, &deadwatch, (void *)philo))
		return ((void *)1);
	while (true)
	{
		if (philo->dead == 1)
			break ;
		if (philo->eat_count == philo->table->meals2eat)
		{
			printf("dis fucker is full\n");
			philo->dead = 1;
			break ;
		}
		if (philo->table->dead == 1 || philo->dead == 1)
			break ;
		think(philo);
		if (philo->table->dead == 1 || philo->dead == 1)
			break ;
		eat(philo);
	}
	pthread_join(philo->pid, NULL);
	return (NULL);
}

void	*deadwatch(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (true)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo_get_time() >= philo->time_to_die)
		{
			print_status(tss(philo->start_time), philo->philo_id, DEAD);
			philo->dead = 1;
			philo->table->dead = 1;
			philo->deb_time = tss(philo->start_time);
		}
		pthread_mutex_unlock(&philo->lock);
		if (philo->dead == 1 || philo->table->dead == 1)
			break ;
	}
	return (NULL);
}
