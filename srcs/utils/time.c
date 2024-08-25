/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:58:21 by ldick             #+#    #+#             */
/*   Updated: 2024/08/25 12:59:22 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

useconds_t	philo_get_time(void)
{
	useconds_t		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

void philo_time_since_start(t_time *t)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	t->current_time = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - t->start_time;
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = philo_get_time();
	while ((philo_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}