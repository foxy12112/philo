/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:21:27 by ldick             #+#    #+#             */
/*   Updated: 2024/07/28 15:37:43 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	philo_five(int argc, char *argv[])
// {
// 	t_philo *philo;
	
// 	philo = init(argc, argv);
	
// }

int	main(int argc, char *argv[])
{
	t_table		table;

	if (argc == 5 || argc == 6)
	{
		parse(&table, argv);
		// init(&table, argv);
		// start(&table);
		// clean(&table);
	}
	// else
	// {
	// 	error_exit("Wrong input\n")
	// }
	// close_all;
	// free_all;
}
