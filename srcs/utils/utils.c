/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:41:27 by ldick             #+#    #+#             */
/*   Updated: 2024/12/04 15:00:55 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] != '\0' && str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == -1)
		return (nbr * -1);
	return (nbr);
}

long	ft_atol(const char *str)
{
	long	i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0' && (str[i] == 32
			|| str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] != '\0' && str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == -1)
		return (nbr * -1);
	return (nbr);
}

void	ft_freeall(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
		free(table->forks);
	while (i < table->philo_amount)
	{
		if (table->philo[i])
			free(table->philo[i]);
		i++;
	}
	if (table->philo)
		free(table->philo);
	if (table->pid)
		free(table->pid);
}

void	ft_end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->start);
	pthread_mutex_destroy(&table->stop);
	ft_freeall(table);
}
