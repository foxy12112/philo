/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/11/25 19:36:54 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	table->philo[0]->start_time = table->start_time;
	if (pthread_create(&table->pid[0], NULL, &philo_one, table->philo[0]))
		return ;
	pthread_join(table->pid[0], NULL);
	return ;
}

void	*philo_one(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->table->start);
	pthread_mutex_unlock(&philo->table->start);
	think(philo);
	print_status(philo->philo_id, FORK, philo->table);
	ft_usleep(philo->table->time2die);
	print_status(philo->philo_id, DEAD, philo->table);
	philo->table->dead = 1;
	return (NULL);
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
	while (true)
	{
		if (eat(philo) == 2)
			return (NULL);
		if (think(philo) == 2)
			return (NULL);
	}
	return (NULL);
}

void	*deadwatch(void *table_ptr)
{
	t_table	*table;
	int i;
	
	i = 0;
	table = (t_table *)table_ptr;
	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
	while (true)
	{
		while(i < table->philo_amount)
		{
			pthread_mutex_lock(&table->philo[i]->lock);
			if (philo_get_time() >= table->philo[i]->time_to_die && table->philo[i]->eating == 0)
			{
				print_status(table->philo[i]->philo_id, DEAD, table);
				pthread_mutex_lock(&table->stop);
				table->philo[i]->dead = 1;
				table->dead = 1;
				table->stup = 1;
				pthread_mutex_unlock(&table->stop);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philo[i]->lock);
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	*milk(void *table_ptr)
{
	t_table	*table;
	int i;

	i = 0;
	table = (t_table *)table_ptr; 
	while (table->dead == 0)
	{
		while(i < table->philo_amount)
		{
			pthread_mutex_lock(&table->stop);
			if (table->philo[i]->eat_count == table->meals2eat)
			{
				table->all_full++;
				table->philo[i]->eat_count = 9999999;
			}
			if (table->all_full == table->philo_amount)
			{
				table->stup = 1;
				return (pthread_mutex_unlock(&table->stop), NULL);
			}
			pthread_mutex_unlock(&table->stop);
			i++;
		}
		i = 0;
	}
	return (NULL);
}