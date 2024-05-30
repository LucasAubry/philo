/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/30 20:52:14 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);	
	data->die = 0;
	if (argc == 6)
		data->nbr_of_meals = ft_atol(argv[5]);	
	else
		data->nbr_of_meals = -1;
}

//argv[1] = nbr de philo et nbr de fourchettes 200
//argv[2] = temps avant de mourrire sans manger en millisecondes int max
//argv[3] = temps pour manger en millisecondes int max
//argv[4] = temps pour dormir em millisecondes int max
//argv[5](optionelle) = nombre de repas que les philos doivent faire int max


int	main(int argc, char **argv)
{
	t_data data;
	t_philo *philo = NULL;
	int i = 0;

	if (new_error(argc, argv))
		return (0);
	init_data(argc, argv, &data);

	if (error_advanced(data))
		return (0);
	philo = malloc(sizeof(t_philo) * data.nbr_philo);
	if (!philo)
		return (print_error(ERR_MALLOC));
	if (!init_philo(&data, philo))
		return (0);
	if (!make_philo(data, philo))
		return (0);	
	if (if_is_dead(&data, philo) == 1)
	{
		while (i < data.nbr_philo)
		{
			pthread_join(philo->tid, NULL);
			i++;
		}
		return (EXIT_SUCCESS);
	}
}
