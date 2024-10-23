/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/23 14:02:08 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_table table;
	// expect 4 or 5 inputs;
	// if (argc == 5 || argc == 6)
	init(argc, argv, &table);
	// else
	// 	return (printf("error, argument count\n"));

	printf("%ld\n", philo_get_time());
	printf("%ld\n", table.start_time);
	printf("%ld\n", tss(&table));
	ft_usleep(5000);
	printf("%ld\n", tss(&table));
	return (0);
}
