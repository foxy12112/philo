/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/11/04 16:17:29 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	multi_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		pthread_create(&table->pid[i], NULL, &philo_routine, table->philo[i]);
		i++;
	}
}

static void	wait_for_threads(t_table *table)
{
	int	i;

	i = 0;
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
	debug(&table);
	if (table.philo_amount > 1)
		multi_philo(&table);
	else
		one_philo(&table);
	wait_for_threads(&table);
	log_philo_data(&table);
	ft_end(&table);
	return (0);
}
