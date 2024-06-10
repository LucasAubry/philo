/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:20 by laubry            #+#    #+#             */
/*   Updated: 2024/06/10 16:30:50 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_error(char **argv, int args)
{
	int	i;

	i = 0;
	while (argv[args][i] == '0')
		i++;
	if (!argv[args][i])
		return (print_error(ERR_ARGS));
	if (ft_strlen(argv[args] + i) >= 9)
		return (print_error(ERR_ARGS));
	i = 0;
	while (argv[args][i])
	{
		if (argv[args][i] >= '0' && argv[args][i] <= '9')
			i++;
		else
			return (print_error(ERR_ARGS));
	}
	return (1);
}

int	new_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
		return (print_error(ERR_ARGS));
	while (i != argc)
	{
		if (!data_error(argv, i))
			return (0);
		i++;
	}
	return (1);
}

int	error_advanced(t_data data)
{
	if (data.nbr_philo > 200)
		return (print_error(ERR_TOO_PHILO));
	else
		return (1);
}
