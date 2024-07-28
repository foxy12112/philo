/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:46:21 by ldick             #+#    #+#             */
/*   Updated: 2024/07/28 15:48:51 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;
	
	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Malloc Error");
	return(ret);
	
}

void	safe_mutex_handle(pthread_mutex_t)