/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/12/02 23:57:05 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	table->philo[0]->start_time = table->start_time;
	if (pthread_create(&table->pid[0], NULL, &philo_one, table->philo[0]))
		return ;
	pthread_join(table->pid[0], NULL);
	ft_end_one(table);
	return ;
}

void	*philo_one(void *philo_ptr)
{
	t_philo	*philo;

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
	pthread_mutex_lock(&philo->time);
	philo->time_to_die = philo->table->time2die + philo_get_time();
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_unlock(&philo->table->start);
	think(philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->table->time2eat / 10);
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
	int		i;

	i = 0;
	table = (t_table *)table_ptr;
	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
	while (true)
	{
		while (i < table->philo_amount)
		{
			if (get_stop_flag(table) == 1)
				return (NULL);
			pthread_mutex_lock(&table->philo[i]->time);
			pthread_mutex_lock(&table->stop);
			if (!table->stup && philo_get_time() >= table->philo[i]->time_to_die)
			{
				printf("%lu %d %s\n", tss(table), i, DEAD);
				table->stup = 1;
				return (pthread_mutex_unlock(&table->stop), NULL);
			}
			pthread_mutex_unlock(&table->stop);
			pthread_mutex_unlock(&table->philo[i]->time);
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	*milk(void *table_ptr)
{
	t_table		*table;
	int			i;

	i = 0;
	table = (t_table *)table_ptr;
	while (1)
	{
		while (i < table->philo_amount)
		{
			if (get_stop_flag(table) == 1)
				return (NULL);
			pthread_mutex_lock(&table->philo[i]->eat_cont);
			if (table->philo[i]->eat_count == table->meals2eat)
			{
				table->all_full++;
				table->philo[i]->eat_count = table->philo[i]->eat_count + 1;
			}
			pthread_mutex_unlock(&table->philo[i]->eat_cont);
			if (table->all_full == table->philo_amount)
				return (ft_set_flag(&table), NULL);
			i++;
		}
		i = 0;
	}
	return (NULL);
}
