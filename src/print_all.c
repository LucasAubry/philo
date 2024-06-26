/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:20:27 by laubry            #+#    #+#             */
/*   Updated: 2024/06/10 17:15:51 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	print_error(int code_error)
{
	if (code_error == ERR_ARGS)
		print_message("ERREUR D'ARGUMENTS");
	else if (code_error == ERR_CREATE_MUTEX)
		print_message("ERREUR MUTEX");
	else if (code_error == ERR_CREATE_PHILO)
		print_message("ERREUR PHILO");
	else if (code_error == ERR_TOO_PHILO)
		print_message("ERREUR TROP DE PHILO");
	else
		return (1);
	return (0);
}

int	print_philo_eat_all(t_philo *philo, int mutex)
{
	if (!mutex)
		pthread_mutex_lock(&philo->data->death);
	if (philo->data->die != 1)
	{
		if (philo->data->philo_eat_all == 1)
			philo->data->die = 1;
		pthread_mutex_lock(&philo->data->print);
		printf("%ld les philo on tout manger \n",
			get_time(philo->data->time_start));
		pthread_mutex_unlock(&philo->data->print);
	}
	if (!mutex)
		pthread_mutex_unlock(&philo->data->death);
	return (1);
}

int	print_philo_is_dead(t_philo *philo, int i)
{
	if (philo->data->die == 1)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ld le philo[%d] vient de mourir (le con)\n",
			get_time(philo->data->time_start), i);
		pthread_mutex_unlock(&philo->data->print);
	}
	return (1);
}

void	print_philo(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->die != 1)
	{
		pthread_mutex_lock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->death);
		printf("%ld the philo[%d] %s",
			get_time(philo->data->time_start), philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_unlock(&philo->data->death);
	return ;
}
