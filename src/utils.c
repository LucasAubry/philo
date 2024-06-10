/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:40:13 by laubry            #+#    #+#             */
/*   Updated: 2024/06/10 13:21:10 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	long			i;
	long			j;
	long long		n;

	i = 0;
	j = 1;
	n = 0;
	while (((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (j * n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->nbr_of_eat < philo->data->nbr_of_meals)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (0);
	}
	else
	{
		philo->data->philo_eat_all = 1;
		philo->is_ok = 0;
		pthread_mutex_unlock(&philo->data->death);
		return (1);
	}
}
