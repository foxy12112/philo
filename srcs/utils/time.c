/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:58:21 by ldick             #+#    #+#             */
/*   Updated: 2024/12/03 14:39:41 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	philo_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	tss(t_table *table)
{
	long	ret;

	pthread_mutex_lock(&table->time);
	ret = philo_get_time() - table->start_time;
	pthread_mutex_unlock(&table->time);
	return (ret);
}

void	ft_usleep(long eepy_time)
{
	long	start;

	start = philo_get_time();
	while ((philo_get_time() - start) < eepy_time)
		usleep(eepy_time / 2);
}

int	get_stop_flag(t_table *table)
{
	int	tmp;

	pthread_mutex_lock(&table->stop);
	tmp = table->stop_flag;
	pthread_mutex_unlock(&table->stop);
	return (tmp);
}
