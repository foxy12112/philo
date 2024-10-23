/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/10/23 13:09:10 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static int	init_philos(t_table *table);

int init(int argc, char *argv[], t_table *table)
{
	/////////////////// t_table	*table;

	/////////////////// table = malloc(sizeof(t_table));
	/////////////////// if (!table)
	/////////////////// 	return (printf("malloc error\n"), 1);
	table->start_time = philo_get_time();
	// table->meals2eat = -1;
	// table->philo_amount = ft_atoi(argv[1]);
	// table->time2die = ft_atol(argv[2]);
	// table->time2eat = ft_atol(argv[3]);
	// table->time2sleep = ft_atol(argv[4]);
	// if (argc == 6)
	// 	table->meals2eat = ft_atoi(argv[5]);
	// init_philos(table);
	return (1);
}

// static int	init_philos(t_table *table)
// {
// 	int	i;

// 	i = 0;

// 	while(i < table->philo_amount)
// 	{
// 		table->philo[i].table = table;
// 		table->philo[i].philo_id = i + 1;
// 		table->philo[i].eat_count = 0;
// 		table->philo[i].sleeping = 0;
// 		table->philo[i].eating = 0;
// 		table->philo[i].time_to_die = table->time2die;
// 		if (!pthread_mutex_init(&table->philo[i].lock, NULL) != 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	init_forks(t_table *table)
// {
// 	int i;

// 	i = 0;
// 	while()
// }