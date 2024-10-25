/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:01:27 by ldick             #+#    #+#             */
/*   Updated: 2024/10/25 20:15:32 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_check(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i >= argc)
		if (ft_isnum(argv[i]))
			return (printf("non number character in arg %d\n", i), 1);
	if (ft_atoi(argv[1]) > 200)
		return (printf("more than 200 philos\n"), 1);
	if (ft_atoi(argv[1]) <= 0)
		return (printf("less than 1 philo\n"), 1);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (printf("not enough time to eat, sleep or not starve"), 1);
	return (0);
}
