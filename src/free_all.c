/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:25:10 by laubry            #+#    #+#             */
/*   Updated: 2024/06/05 18:58:40 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delet_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nbr_philo)
	{
		pthread_mutex_destroy(&philo[i].time);
		pthread_mutex_destroy(&philo[i].fork_left);
	}
	pthread_mutex_destroy(&philo->data->print);
	
}

int	free_all(t_philo *philo)
{
//	printf("oui");
//	philo->id = 0;
	delet_mutex(philo);
	free(philo);
	return (0);
}

