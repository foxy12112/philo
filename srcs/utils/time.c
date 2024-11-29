/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:58:21 by ldick             #+#    #+#             */
/*   Updated: 2024/11/29 15:19:44 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	philo_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	tss(long start_time)
{
	long	ret;

	ret = philo_get_time() - start_time;
	return (ret);
}

void	ft_usleep(long eepy_time)
{
	long	start;

	start = philo_get_time();
	while ((philo_get_time() - start) < eepy_time)
		usleep(eepy_time / 2);
}

int get_stop_flag(t_table *table)
{
	int tmp;
	pthread_mutex_lock(&table->stop);
	tmp = table->stup;
	pthread_mutex_unlock(&table->stop);
	return(tmp);
}

