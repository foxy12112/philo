/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/12/04 17:55:47 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_status(int id, char *status, t_table *table)
{
	pthread_mutex_lock(&table->stop);
	if (table->stop_flag == 1)
		return (pthread_mutex_unlock(&table->stop), 2);
	printf("%lu %d %s\n", tss(table), id, status);
	pthread_mutex_unlock(&table->stop);
	return (0);
}
