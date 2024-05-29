/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:51:46 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/28 19:26:43 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	check_error_2(t_data *data, int i, t_philo *philo)
{
	if (data->time_to_eat <= 0)
		i = print_error(ERR_TIME_TO_EAT_TO_SHORT, philo);
	if (data->time_to_sleep <= 0)
		i = print_error(ERR_TIME_TO_SLEEP_TO_SHORT, philo);
	return (i);
}

int	check_error_max(t_data *data, int i, t_philo *philo)
{
	if (data->nbr_philo > 200)
		i = print_error(ERR_TOO_MANY_PHILO, philo);
	if (data->time_to_die > INT_MAX)
		i = print_error(ERR_TO_DIE_NO_EAT_TO_LONG, philo);
	if (data->time_to_eat > INT_MAX)
		i = print_error(ERR_TIME_TO_EAT_TO_LONG, philo);
	if (data->time_to_sleep > INT_MAX)
		i = print_error(ERR_TIME_TO_SLEEP_TO_LONG, philo);
	return (i);
}

int	check_error(int argc, t_data *data, t_philo *philo)
{
	int i = 0;
	if (argc != 5 && argc != 6)
		i = print_error(ERR_ARGS, philo);
	if (data->nbr_philo <= 0)
		i = print_error(ERR_NBR_PHILO, philo);
	if (data->time_to_die <= 0)
		i = print_error(ERR_TIME_TO_DIE_NO_EAT_TO_SHORT, philo);
	i = check_error_2(data, i, philo);
	i = check_error_max(data, i, philo);
	if (i == 1)
		return (0);
	else
		return (1);
}

