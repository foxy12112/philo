/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:37:48 by ldick             #+#    #+#             */
/*   Updated: 2024/11/03 16:26:15 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	debug(t_table *table)
{
	FILE	*logfile;
	int		i;

	i = 0;
	logfile = fopen("output.log", "w");
	if (!logfile)
		return ;
	fprintf(logfile, "Philosopher Table Initialization:\n");
	fprintf(logfile, "\tPhilosopher Amount: %u\n", table->philo_amount);
	fprintf(logfile, "\tTime to Die: %ld\n", table->time2die);
	fprintf(logfile, "\tTime to Eat: %ld\n", table->time2eat);
	fprintf(logfile, "\tTime to Sleep: %ld\n", table->time2sleep);
	fprintf(logfile, "\tMeals to Eat: %d\n", table->meals2eat);
	fprintf(logfile, "\tStart Time: %ld\n", table->start_time);
	while (i < table->philo_amount)
	{
		fprintf(logfile, "\n\tPhilosopher %d:\n", i + 1);
		fprintf(logfile, "\t\tPhilosopher ID: %d\n", table->philo[i]->philo_id);
		fprintf(logfile, "\t\tPhilosopher fork_r: %p\n",
			table->philo[i]->fork_r);
		fprintf(logfile, "\t\tPhilosopher fork_l: %p\n",
			table->philo[i]->fork_l);
		fprintf(logfile, "\t\tEat Count: %d\n", table->philo[i]->eat_count);
		fprintf(logfile, "\t\tSleeping: %d\n", table->philo[i]->sleeping);
		fprintf(logfile, "\t\tImportance: %d\n", table->philo[i]->importance);
		fprintf(logfile, "\t\tTime to Die: %ld\n",
			table->philo[i]->time_to_die);
		fprintf(logfile, "\t\tStart Time: %ld\n", table->philo[i]->start_time);
		fprintf(logfile, "\t\tDead: %d\n", table->philo[i]->dead);
		i++;
	}
	fclose(logfile);
}

void	log_philo_data(t_table *table)
{
	FILE	*logfile;
	int		i;

	i = 1;
	logfile = fopen("output_dead.log", "w");
	if (!logfile)
		return ;
	if (!table || !table->philo)
		return ;
	while (i < table->philo_amount)
	{
		if (!table->philo[i])
			break ;
		fprintf(logfile, "\n\tPhilosopher ID: %d\n", table->philo[i]->philo_id);
		fprintf(logfile, "\tPhilosopher fork_r: %p\n", table->philo[i]->fork_r);
		fprintf(logfile, "\tPhilosopher fork_l: %p\n", table->philo[i]->fork_l);
		fprintf(logfile, "\tEat Count: %d\n", table->philo[i]->eat_count);
		fprintf(logfile, "\tSleeping: %d\n", table->philo[i]->sleeping);
		fprintf(logfile, "\tImportance: %d\n", table->philo[i]->importance);
		fprintf(logfile, "\tTime to Die: %ld\n", table->philo[i]->time_to_die);
		fprintf(logfile, "\tStart Time: %ld\n", table->philo[i]->start_time);
		fprintf(logfile, "\tDead: %d\n", table->philo[i]->dead);
		fprintf(logfile, "\ttime alive: %ld\n", tss(table->start_time));
		i++;
	}
	fclose(logfile);
}
