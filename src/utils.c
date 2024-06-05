/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:40:13 by laubry            #+#    #+#             */
/*   Updated: 2024/06/05 17:54:41 by laubry           ###   ########.fr       */
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
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
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
	if (philo->data->nbr_of_meals == -1)
		return (0);
	if (philo->nbr_of_eat < philo->data->nbr_of_meals)
		return (0);
	else
		return (1);
}
