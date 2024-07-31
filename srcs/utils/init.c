/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/07/31 15:13:23 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(char *argv[], t_philo *philo)
{
	philo->data->dead = false;
	printf("test1\n");
	philo->data->full = false;
	printf("test2\n");
	philo->data->meals_eaten = 0;
	printf("test3\n");
	philo->time->start_time = philo_get_time();
	printf("test4\n");
	philo->data->philo_nbr = ft_atol(argv[1]);
	printf("test5\n");
	philo->time->time_to_die = ft_atol(argv[2]);
	printf("test6\n");
	philo->time->time_to_eat = ft_atol(argv[3]);
	printf("test7\n");
	philo->time->time_to_sleep = ft_atol(argv[4]);
	printf("test8\n");
	if (argv[5])
		philo->data->meals_amount = ft_atol(argv[5]);
	else if (!argv[5])
		philo->data->meals_amount = -1;
	printf("%u\n", philo->time->start_time);
}
