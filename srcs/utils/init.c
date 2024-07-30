/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:05 by ldick             #+#    #+#             */
/*   Updated: 2024/07/30 13:23:58 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_table *table)
{
	table->end = false;
	table->philo = safe_malloc(table->philo_nbr);
	table->start = philo_get_time();
	printf("%zu\n", table->start);
	time_since_start(table);
	// make_philos; // TODO
}

int	make_philos(t_philo *philo, int i)
{
	philo->id = i + 1;
	philo->thread_id = 0;
	pthread_mutex_init(&philo->fork_lock, NULL);
	pthread_mutex_init(&philo->meal_lock, NULL);
	philo->last_meal = 0;
}
int	idkyet(t_table *table)
{
	int			i;
	t_list		*philos;

	i = -1;
	philos = 0;
	while (++i < table->philo_nbr)
		ft_lstadd_back(&philos, ft_lstnew(make_philos(&table->philo, i)));
	return (philos);
}
