/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:56:43 by laubry            #+#    #+#             */
/*   Updated: 2024/06/07 17:33:05 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].nbr_of_eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].is_ok = 1;
		if (pthread_mutex_init(&philo[i].time, NULL) != 0)
			return (print_error(ERR_CREATE_MUTEX));
		gettimeofday(&philo[i].last_eat, NULL);
		if (pthread_mutex_init(&philo[i].fork_left, NULL) != 0)
			return (print_error(ERR_CREATE_MUTEX));
		if (i > 0)
			philo[i].fork_right = &philo[i -1].fork_left;
		i++;
	}
	if (i >= 1)
		philo[0].fork_right = &philo[i -1].fork_left;
	return (1);
}

int	make_philo(t_data data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data.nbr_philo)
	{
		if (pthread_create(&philo[i].tid, NULL, routine, &philo[i]) != 0)
			return (print_error(ERR_CREATE_PHILO));
		usleep(1000);
		i++;
	}
	return (1);
}

int if_is_end(t_data *data, t_philo *philo)
{
	long 	i;
	int		j;

	i = -1;
	j = 0;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_lock(&philo[i].time);
		if (get_time(philo[i].last_eat) > data->time_to_die)
		{
			pthread_mutex_unlock(&philo[i].time);
			pthread_mutex_lock(&philo->data->death);
			data->die = 1;
			pthread_mutex_unlock(&philo->data->death);
			return (print_philo_is_dead(philo, philo[i].id));
		}
		pthread_mutex_unlock(&philo[i].time);
		pthread_mutex_lock(&philo[i].data->death);
		if (philo[i].is_ok == 0)
			j++;
		if (j == philo->data->nbr_philo)
			return (print_philo_eat_all(philo));
		pthread_mutex_unlock(&philo[i].data->death);
	}
	return (0);
}
