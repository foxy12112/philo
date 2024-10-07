/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/10/07 16:11:56 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	parse(char *argv[], t_philo *philo)
{
	if (has_alpha(argv[1]) == 0 || has_alpha(argv[2]) == 0
		|| has_alpha(argv[3]) == 0 || has_alpha(argv[4]) == 0)
		return (1);
	if (ft_atoi(argv[1]) >= 200 || ft_atoi(argv[1]) <= 0
		|| ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (1);
	return (0);
}

t_philo	init(char *argv[], t_philo *philo, t_time *time)
{
	philo->dead = false;
	philo->full = false;
	philo->meals_eaten = 0;
	time->start_time = philo_get_time();
	philo->philo_nbr = ft_atoi(argv[1]);
	time->time_to_die = ft_atoi(argv[2]);
	time->time_to_eat = ft_atoi(argv[3]);
	time->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->meals_till_full = ft_atoi(argv[5]);
	else if (!argv[5])
		philo->meals_till_full = -1;
	return (*philo);
}

void	init_philos(char *argv[], t_philo *philo)
{
	int	i;
	int	num;

	num = philo->philo_nbr;
	while (i < num)
	{
	}
}
