/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/12/02 23:35:50 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	multi_philo(t_table *table)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&table->time);
	table->start_time = philo_get_time();
	pthread_mutex_unlock(&table->time);
	while (i < table->philo_amount)
	{
		pthread_mutex_lock(&table->philo[i]->time);
		table->philo[i]->time_to_die = philo_get_time() + table->time2die;
		pthread_mutex_unlock(&table->philo[i]->time);
		pthread_create(&table->pid[i], NULL, &philo_routine, table->philo[i]);
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&table->start);
	while (i < table->philo_amount)
	{
		pthread_join(table->pid[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (error_check(argc, argv))
		return (1);
	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	if (table.philo_amount == 1)
		return (one_philo(&table), 0);
	if (table.meals2eat != -1)
		pthread_create(&table.milk, NULL, &milk, &table);
	if (table.philo_amount > 1)
	{
		pthread_mutex_lock(&table.start);
		pthread_create(&table.deadwatch, NULL, &deadwatch, &table);
		multi_philo(&table);
		pthread_join(table.deadwatch, NULL);
		if (table.meals2eat != -1)
			pthread_join(table.milk, NULL);
		return (ft_end(&table), 0);
	}
	return (0);
}
