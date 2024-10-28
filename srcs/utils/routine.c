/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/10/28 13:47:09 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_routine(t_philo *philo)
{
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	while (philo->time_to_die >= philo_get_time()
		|| philo->eat_count > philo->table->meals2eat)
	{
		think(philo);
		eat(philo);
	}
}
