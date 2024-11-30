/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:39:58 by ldick             #+#    #+#             */
/*   Updated: 2024/11/30 19:30:53 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//TODO

// int	print_status(long time, int id, int status, t_table *table)
// {
// 	if (table->all_full == table->philo_amount || table->dead == 1)
// 		return (2);
// 	pthread_mutex_lock(&table->spaek);
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
// 	pthread_mutex_unlock(&table->spaek);
// 	return (0);
// }

int	print_status(int id, char *status, t_table *table)
{
	if (get_stop_flag(table) == 1)
		return (2);
	printf("%lu %d %s\n", tss(table), id, status);
	return (0);
}

// void	print_status(long time, int id, int status, t_table *table)
// {
// 	FILE *log_file = fopen("output_routine.log", "a");
// 	pthread_mutex_lock(&table->spaek);
// 	if (!log_file)
// 	{
// 		perror("Failed to open log file");
// 		return ;
// 	}
// 	(void)time;
// 	if (status == EAT)
// 	{
// 		printf("%lu %d is eating\n", tss(table->start_time), id);
// 		fprintf(log_file, "%lu %d is eating\n", tss(table->start_time), id);
// 	}
// 	else if (status == FORK)
// 	{
// 		printf("%lu %d has taken a fork\n", tss(table->start_time), id);
// 		fprintf(log_file, "%lu %d has taken a fork\n", tss(table->start_time), id);
// 	}
// 	else if (status == SLEEP)
// 	{
// 		printf("%lu %d is sleeping\n", tss(table->start_time), id);
// 		fprintf(log_file, "%lu %d is sleeping\n", tss(table->start_time), id);
// 	}
// 	else if (status == DEAD)
// 	{
// 		printf("%lu %d died\n", tss(table->start_time), id);
// 		fprintf(log_file, "%lu %d died\n", tss(table->start_time), id);
// 	}
// 	else if (status == THINK)
// 	{
// 		printf("%lu %d is thinking\n", tss(table->start_time), id);
// 		fprintf(log_file, "%lu %d is thinking\n", tss(table->start_time), id);
// 	}
// 	fclose(log_file);
// 	pthread_mutex_unlock(&table->spaek);
// }