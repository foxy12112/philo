/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:48 by ldick             #+#    #+#             */
/*   Updated: 2024/10/21 13:33:23 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philos(t_table *table);

int init(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (printf("malloc error\n"), 1);
	table->meals2eat = -1;
	table->philo_amount = ft_atoi(argv[1]);
	table->time2die = ft_atol(argv[2]);
	table->time2eat = ft_atol(argv[3]);
	table->time2sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->meals2eat = ft_atoi(argv[5]);
	init_philos(table);
	return (1);
}

static int	init_philos(t_table *table)
{
	int	num;
	int	i;

	i = 1;
	num = table->philo_amount;
	while(i < num)
	{
		table->philo[i].
		i++;
	}
	printf("%d\n", i);
	return (1);
}
