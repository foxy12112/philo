/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:05 by ldick             #+#    #+#             */
/*   Updated: 2024/07/29 13:35:40 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_table *table)
{
	table->end = false;
	table->philo = safe_malloc(table->philo_nbr);
	table->start
	make_philos; // TODO
}

void	make_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philo->id = i;
		if (pthread_create(&table->philo->thread_id[i], NULL, philo_loop(table),
				&table->philo->id))
			return (write(2, "Failed to create Thread\n", 25), 1);
		i++;
	}
}