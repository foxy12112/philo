/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:37:17 by ldick             #+#    #+#             */
/*   Updated: 2024/07/30 11:47:50 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_timestamp(useconds_t timestamp, int philo_id, char *status)
{
	printf("[%l] %d %s\n", timestamp, philo_id, status);
}
