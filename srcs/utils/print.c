/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/11/06 14:43:32 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	print_status(long time, int id, int status)
// {
// 	if (status == EAT)
// 		printf("%lu %d is eating\n", time, id);
// 	else if (status == FORK)
// 		printf("%lu %d has taken a fork\n", time, id);
// 	else if (status == SLEEP)
// 		printf("%lu %d is sleeping\n", time, id);
// 	else if (status == DEAD)
// 		printf("%lu %d died\n", time, id);
// 	else if (status == THINK)
// 		printf("%lu %d is thinking\n", time, id);
// }

void	print_status(long time, int id, int status)
{
	FILE *log_file = fopen("output_routine.log", "a");
	if (!log_file)
	{
		perror("Failed to open log file");
		return ;
	}

	if (status == EAT)
	{
		printf("%lu %d is eating\n", time, id);
		fprintf(log_file, "%lu %d is eating\n", time, id);
	}
	else if (status == FORK)
	{
		printf("%lu %d has taken a fork\n", time, id);
		fprintf(log_file, "%lu %d has taken a fork\n", time, id);
	}
	else if (status == SLEEP)
	{
		printf("%lu %d is sleeping\n", time, id);
		fprintf(log_file, "%lu %d is sleeping\n", time, id);
	}
	else if (status == DEAD)
	{
		printf("%lu %d died\n", time, id);
		fprintf(log_file, "%lu %d died\n", time, id);
	}
	else if (status == THINK)
	{
		printf("%lu %d is thinking\n", time, id);
		fprintf(log_file, "%lu %d is thinking\n", time, id);
	}

	fclose(log_file);
}