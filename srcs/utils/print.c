/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/10/23 11:09:23 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	print_eat(long time, int id)
{
	printf("%lu %d is eating", time, id);
}

void	print_die(long time, int id)
{
	printf("%lu %d died", time, id);
}

void	print_sleep(long time, int id)
{
	printf("%lu %d is sleeping", time, id);
}

void	print_think(long time, int id)
{
	printf("%lu %d is thinking", time, id);
}

void	print_fork(long time, int id)
{
	printf("%lu %d has taken a fork", time, id);
}
