/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:21:29 by laubry            #+#    #+#             */
/*   Updated: 2024/06/10 16:56:18 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_unlock_fork(t_philo *philo, int i)
{
	if (i == 1)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->fork_left);
			print_philo(philo, "has taken a fork left\n");
			pthread_mutex_lock(philo->fork_right);
			print_philo(philo, "has taken a fork right\n");
		}
		else
		{
			pthread_mutex_lock(philo->fork_right);
			print_philo(philo, "has taken a fork right\n");
			pthread_mutex_lock(&philo->fork_left);
			print_philo(philo, "has taken a fork left\n");
		}
	}
	else if (i == 0)
	{
		print_philo(philo, "has drop a fork\n");
		pthread_mutex_unlock(&philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
}

void	is_eating(t_philo *philo)
{
	lock_unlock_fork(philo, 1);
	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(&philo->time);
	print_philo(philo, "is eating\n");
	pthread_mutex_lock(&philo->time);
	philo->nbr_of_eat += 1;
	pthread_mutex_unlock(&philo->time);
	usleep(philo->data->time_to_eat * 1000);
	lock_unlock_fork(philo, 0);
}

void	is_thinking(t_philo *philo)
{
	print_philo(philo, "is thinking\n");
}

void	is_sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
}

void	*routine(void *buff)
{
	t_philo	*philo;

	philo = (t_philo *)buff;
	while (1)
	{
		pthread_mutex_lock(&philo->data->death);
		if (philo->data->die == 1)
		{
			pthread_mutex_unlock(&philo->data->death);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death);
		is_eating(philo);
		if (philo->data->nbr_of_meals != -1)
			check_meals(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
