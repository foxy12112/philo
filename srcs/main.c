/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/30 17:02:52 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	main(int argc, char *argv[])
// {
// 	t_table	table;
// 	printf("test1\n");
// 	if (argc == 5 || argc == 6)
// 		init(argc, argv, &table);
// 	printf("test2\n");
// 	// pthread_create(one_philo(table->philo), );
// 	// else
// 	// 	return (printf("error, argument count\n"));
// 	// if (ft_atoi(argv[1]) > 1 && ft_atoi(argv[1]) < 200)
// 	// philo_routine(table.philo);
// 	one_philo(&table);
// 	error_check(argc, argv);
// 	return (0);
// }


#include <assert.h>

void test_philo_routine_with_different_times()
{
	t_table table;
	char *argv2[] = {"./philo", "1", "500", "100", "100"};
	int argc = 5;
	
	printf("1\n");
	ft_usleep(500);
	printf("2\n");
	assert(init(argc, argv2, &table) == 1);
	one_philo(&table);
	pthread_join(table.philo[0].pid, NULL);
}

int main()
{
	test_philo_routine_with_different_times();
	return 0;
}