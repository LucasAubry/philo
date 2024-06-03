/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:56:43 by laubry            #+#    #+#             */
/*   Updated: 2024/06/03 21:30:24 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data, t_philo *philo)
{
	unsigned int i = 0;

	while (i < data->nbr_philo)
	{
		philo[i].nbr_of_eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].id = i;
		philo[i].data = data;
		philo[i].is_ok = 1;
		philo[i].last_eat = get_time(); 
		if (pthread_mutex_init(&philo[i].fork_left, NULL) != 0)
			return(print_error(ERR_CREATE_MUTEX));
		if (i > 0)
			philo[i].fork_right = &philo[i-1].fork_left;
		i++;
	}	
	if (i >= 1)
		philo[0].fork_right = &philo[i-1].fork_left;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (print_error(ERR_CREATE_MUTEX));
	if (pthread_mutex_init(&data->time, NULL) != 0)
		return (print_error(ERR_CREATE_MUTEX));
	return (1);
}

int	make_philo(t_data data, t_philo *philo)
{
	int i = 0;

	
	while (i < data.nbr_philo)
	{
		if (pthread_create(&philo[i].tid, NULL, routine, &philo[i]) != 0)
			return (print_error(ERR_CREATE_PHILO));
		i++;
	}
	return (1);
}

int if_is_dead(t_data *data, t_philo *philo)
{
	long i;
	int j;
	while(1)
	{
		i = 0;
		j = 0;
		while (i < data->nbr_philo)
		{
		//a corriger demain pour la mort
		////
		////
		///
		///
		//
		//
		//
		
		if ((get_time() - philo->last_eat) == data->time_to_die)
				data->die = 1;
		//
		//
		//
		//
			if (philo[i].data->die == 1)
				return (print_philo_is_dead(philo, i));
			if (philo->is_ok == 0)
				j++;
			i++;
		}
		if (j == philo->data->nbr_philo)
			return (print_philo_eat_all(philo));	
	}
}

