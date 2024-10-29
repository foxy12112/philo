/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/29 15:14:23 by ldick            ###   ########.fr       */
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


void test_philo_routine()
{
    t_table table;
    char *argv[] = {"./philo", "1", "800", "200", "200"};
    int argc = 5;

    printf("Running test_philo_routine...\n");

    if (!init(argc, argv, &table))
    {
        printf("Initialization failed\n");
        return;
    }

    // // Create threads for each philosopher
    // for (unsigned int i = 0; i < table.philo_amount; i++)
    // {
    //     pthread_create(&table.philo[i].pid, NULL, (void *(*)(void *))philo_routine, &table.philo[i]);
    // }
	one_philo(&table);
    // Wait for all threads to finish
    pthread_join(table.philo[0].pid, NULL);

    printf("test_philo_routine passed\n");
}

int main()
{
    test_philo_routine();
    return 0;
}