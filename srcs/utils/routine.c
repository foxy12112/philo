/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:54:02 by ldick             #+#    #+#             */
/*   Updated: 2024/10/29 15:16:44 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	one_philo(t_table *table)
{
	if (pthread_create(&table->pid[1], NULL, (void *(*)(void *))philo_routine, &table->pid[1]))
		return ;
	pthread_detach(table->pid[1]);
	while (!table->dead)
		ft_usleep(0);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	philo->time_to_die = philo_get_time() + philo->table->time2die;
	while (true)
	{
		if (philo->time_to_die <= philo_get_time())
		{
			printf("%ld\n", philo->start_time);
			printf("%ld\n", tss(philo->start_time));
			return (print_status(tss(philo->table->start_time), philo->philo_id,
					DEAD), NULL);
		}
		if (philo->eat_count >= philo->table->meals2eat)
			return (printf("dis fucker is full\n"), NULL);
		think(philo);
		eat(philo);
	}
	return (NULL);
}
