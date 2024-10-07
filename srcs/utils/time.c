/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:58:21 by ldick             #+#    #+#             */
/*   Updated: 2024/10/07 16:11:45 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	philo_get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (time);
}

long	philo_time_since_start(long start_time)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, NULL);
	ret = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (ret - start_time);
}

int	ft_usleep(long time)
{
	long	start;

	start = philo_get_time();
	while ((philo_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
