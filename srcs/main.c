/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/29 11:09:55 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	// pthread_create(one_philo(table->philo), );
	// else
	// 	return (printf("error, argument count\n"));
	// if (ft_atoi(argv[1]) > 1 && ft_atoi(argv[1]) < 200)
		philo_routine(table.philo);
	error_check(argc, argv);
	return (0);
}
