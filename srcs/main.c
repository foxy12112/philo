/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/11/27 17:02:57 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	multi_philo(t_table *table)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&table->start);
	while (i < table->philo_amount)
	{
		table->philo[i]->time_to_die = philo_get_time() + table->time2die;
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
	pthread_t m;

	if (error_check(argc, argv))
		return (1);
	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	if (table.meals2eat != -1)
	{
		pthread_create(&t, NULL, &milk, &table);
		pthread_detach(t);
		// pthread_join(t, NULL);
	}
	if (table.philo_amount > 1)
	{
		pthread_create(&m, NULL, &deadwatch, &table);
		pthread_detach(m);
		multi_philo(&table);
		// pthread_join(m, NULL);
	}
	else if (table.philo_amount == 1)
	{
		one_philo(&table);
		ft_end_one(&table);
		return(0);
	}
	int i = 0;
	while(i < table.philo_amount)
	{
		printf("--philo_%d--has_eaten_%d_times--\n", i, table.philo[i]->eat_count - 1);
		i++;
	}
	ft_end(&table);
	return (0);
}
//TODO 5 800 200 200 7, stops at 3800ms sometimes if it ends on taking a fork

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