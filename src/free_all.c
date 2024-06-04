/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:25:10 by laubry            #+#    #+#             */
/*   Updated: 2024/06/04 19:37:29 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delet_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nbr_philo)
		pthread_mutex_destroy(&philo[i].fork_left);
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->time);
}

void	free_all(t_philo *philo)
{
	printf("oui");
	philo->id = 0;
//	free(philo);
}
