/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:20 by laubry            #+#    #+#             */
/*   Updated: 2024/05/30 20:54:10 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//si args > max int, si il y a des args, si cest des chiffres
int	data_error(char **argv, int args)
{
	int	i = 0;

	while (argv[args][i] == '0')
		i++;
	if (!argv[args][i])
		return (print_error(ERR_ARGS));
	if (ft_strlen(argv[args] + i) >= 9)
		return(print_error(ERR_ARGS));
	i = 0;
	while (argv[args][i])
	{
		if (argv[args][i] >= '0' && argv[args][i] <= '9')
			i++;
		else
			return(print_error(ERR_ARGS));
	}
	return (0);
}

int	new_error(int argc, char **argv)
{
	int	i = 1;

	if (argc > 6 || argc < 5)
		return(print_error(ERR_ARGS));
	while (i != argc)
	{
		if (data_error(argv, i))
			return(1);
		i++;
	}
	return (0);
}

int	error_advanced(t_data data)
{
	if (data.nbr_philo > 200)
		return(print_error(ERR_TOO_PHILO));
	else
		return (0);
	//suite de args
}
