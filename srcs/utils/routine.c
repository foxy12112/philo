/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/11/13 18:52:23 by ldick            ###   ########.fr       */
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
	pthread_mutex_destroy(table->forks);
	return ;
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->table->start);
	pthread_mutex_unlock(&philo->table->start);
	philo->time_to_die = philo->table->time2die + philo_get_time();
	think(philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->table->time2eat / 2);
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	if (pthread_create(&philo->pid, NULL, &deadwatch, (void *)philo))
		return ((void *)1);
	while (philo->table->dead == 0)
	{
		if (philo->table->meals2eat == philo->eat_count)
			philo->table->all_full++;
		if (philo->table->philo_amount == philo->table->all_full)
			break ;
		eat(philo);
		think(philo);
	}
	pthread_join(philo->pid, NULL);
	return (NULL);
}

void	*deadwatch(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (!philo->table->dead && !philo->dead)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo_get_time() >= philo->time_to_die && philo->eating == 0)
		{
			print_status(tss(philo->start_time), philo->philo_id, DEAD, philo->table);
			philo->dead = 1;
			philo->table->dead = 1;
			philo->deb_time = tss(philo->start_time);
		}
		if (philo->eat_count == philo->table->meals2eat)
		{
			philo->table->all_full++;
			philo->eat_count++;
		}
		pthread_mutex_unlock(&philo->lock);
		if (philo->dead || philo->table->dead || philo->table->all_full == philo->table->philo_amount)
			break ;
	}
	return (NULL);
}
