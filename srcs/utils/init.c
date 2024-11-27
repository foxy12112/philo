/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/11/27 16:41:19 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (table->philo_amount == 1)
	{
		table->philo[0]->fork_r = &table->forks[0];
		table->philo[0]->fork_l = NULL;
	}
	else
	{
		table->philo[0]->fork_r = &table->forks[0];
		table->philo[0]->fork_l = &table->forks[table->philo_amount - 1];
		i = 1;
		while (i < table->philo_amount)
		{
			table->philo[i]->fork_r = &table->forks[i];
			table->philo[i]->fork_l = &table->forks[i - 1];
			i++;
		}
	}
	return (1);
}

static int	init_philos(t_table *table)
{
	int	i;

	i = 0;

	while (i < table->philo_amount)
	{
		table->philo[i]->table = table;
		table->philo[i]->philo_id = i + 1;
		table->philo[i]->eat_count = 0;
		table->philo[i]->start = 0;
		table->philo[i]->eating = 0;
		table->philo[i]->sleeping = 0;
		table->philo[i]->start_time = table->start_time;
		table->philo[i]->time_to_die = table->time2die;
		table->philo[i]->importance = 0;
		table->philo[i]->dead = 0;
		table->philo[i]->fork_l_c = 0;
		table->philo[i]->fork_r_c = 0;
		i++;
	}
	return (1);
}

int	init(int argc, char *argv[], t_table *table)
{
	table->start_time = philo_get_time();
	table->meals2eat = -1;
	table->all_full = 0;
	table->stup = 0;
	table->philo_amount = ft_atoi(argv[1]);
	table->time2die = ft_atol(argv[2]);
	table->time2eat = ft_atol(argv[3]);
	table->time2sleep = ft_atol(argv[4]);
	pthread_mutex_init(&table->start, NULL);
	pthread_mutex_init(&table->stop, NULL);
	table->dead = 0;
	if (argc == 6)
		table->meals2eat = ft_atoi(argv[5]);
	table->pid = malloc((table->philo_amount + 1) * sizeof(pthread_t));
	if (!table->pid)
		return (1);
	table->forks = malloc(table->philo_amount * sizeof(pthread_mutex_t));
	table->philo = malloc(table->philo_amount * sizeof(t_philo *));
	int i = 0;
	while (i < table->philo_amount)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		i++;
	}
	init_philos(table);
	init_forks(table);
	return (1);
}

