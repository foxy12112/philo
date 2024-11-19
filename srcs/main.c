/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/11/19 16:31:30 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	multi_philo(t_table *table)
{
	int			i;

	i = 0;
	 //TODO still confusion but this stsayz for now, works, i think
	pthread_mutex_lock(&table->start);
	while (i < table->philo_amount)
	{
		pthread_create(&table->pid[i], NULL, &philo_routine, table->philo[i]);
		i++;
	}
	table->start_time = philo_get_time();
	i = 0;
	pthread_mutex_unlock(&table->start);
	while(i < table->philo_amount)
	{
		pthread_join(table->pid[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;
	pthread_t t;

	if (error_check(argc, argv))
		return (1);
	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	if (table.meals2eat != -1)
	{
		pthread_create(&t, NULL, &milk, &table.philo);
		pthread_detach(t);
	}
	if (table.philo_amount > 1)
		multi_philo(&table);
	else if (table.philo_amount == 1)
	{
		one_philo(&table);
		ft_end_one(&table);
		return(0);
	}
	ft_end(&table);
	return (0);
}
//TODO 1 philo deadlysignal

// int	main(int argc, char *argv[])
// {
// 	t_table	table;

// 	FILE *log_file = fopen("output_routine.log", "wb"); //TODO Delete
// 	fclose(log_file);
// 	if (error_check(argc, argv))
// 		return (1);
// 	if (argc == 5 || argc == 6)
// 		init(argc, argv, &table);
// 	debug(&table);
// 	if (table.philo_amount > 1)
// 		multi_philo(&table);
// 	else
// 		one_philo(&table);
// 	log_philo_data(&table);
// 	ft_end(&table);
// 	return (0);
// }