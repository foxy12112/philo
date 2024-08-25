/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/08/25 13:54:28 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(char *argv[], t_philo *philo)
{
	philo->data = malloc(sizeof(t_philo_data));
	philo->data->dead = false;
	philo->data->full = false;
	philo->data->meals_eaten = 0;
	philo->time->start_time = philo_get_time();
	philo->data->philo_nbr = ft_atol(argv[1]);
	philo->time->time_to_die = ft_atol(argv[2]);
	philo->time->time_to_eat = ft_atol(argv[3]);
	philo->time->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->data->meals_amount = ft_atol(argv[5]);
	else if (!argv[5])
		philo->data->meals_amount = -1;
}

void	init_philos(char *argv[], t_philo *philo)
{
	int i = philo->data->philo_nb
}
