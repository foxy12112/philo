/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/31 13:37:15 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	multi_philo(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i <= table->philo_amount)
	{
		pthread_create(&table->pid[i], NULL, &philo_routine, &table->philo[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table			table;

	error_check(argc, argv);
	debug(argc, argv, &table);
	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	if (table.philo_amount > 1)
		multi_philo(&table);
	else
		one_philo(&table);
	return (0);
}
