/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/10/25 19:47:04 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(long time, int id, int status)
{
	if (status == EAT)
		printf("%lu %d is eating", time, id);
	else if (status == FORK)
		printf("%lu %d has taken a fork", time, id);
	else if (status == SLEEP)
		printf("%lu %d is sleeping", time, id);
	else if (status == DEAD)
		printf("%lu %d died", time, id);
	else if (status == THINK)
		printf("%lu %d is thinking", time, id);
}
