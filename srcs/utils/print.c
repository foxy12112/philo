/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/08/25 13:49:34 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	taken_fork(useconds_t timestamp, int id)
{
	printf("%d %d has taken fork", timestamp, id);
}

void	eating(useconds_t timestamp, int id)
{
	printf("%d %d is eating", timestamp, id);
}

void	sleeping(useconds_t timestamp, int id)
{
	printf("%d %d is sleeping", timestamp, id);
}

void	thinking(useconds_t timestamp, int id)
{
	printf("%d %d is thinking", timestamp, id);
}

void	died(useconds_t timestamp, int id)
{
	printf("%d %d died", timestamp, id);
}
