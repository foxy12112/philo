/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:38 by ldick             #+#    #+#             */
/*   Updated: 2024/10/25 18:57:14 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_table table;

	if (argc == 5 || argc == 6)
		init(argc, argv, &table);
	else
		return (printf("error, argument count\n"));
	// if (ft_atoi(argv[1]) == 1)
	// 	philo_routine_one(&table);
	// else if (ft_atoi(argv[1]) > 1 && ft_atoi(argv[1]) < 200)
	// 	philo_routine_normal(&table);
	error_check(argc, argv);
	return (0);
}