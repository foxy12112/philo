/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/07 16:11:39 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;
	t_time	time;

	if (argc == 5 || argc == 6)
	{
		parse(argv, &philo);
		init(argv, &philo, &time);
		printf("%ld\n", time.start_time);
		printf("%ld\n", philo_get_time());
		printf("%ld\n", philo_time_since_start(time.start_time));
	}
	return (0);
}
