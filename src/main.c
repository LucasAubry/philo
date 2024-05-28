/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/28 17:36:13 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include "stdio.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);	
	if (argc == 6)
		data->nbr_of_meals = ft_atol(argv[5]);	
	else
		data->nbr_of_meals = -1;
}

int	init_philo(t_data *data, t_philo *philo)
{
	unsigned int i = 0;

	while (i < data->nbr_philo)
	{
		philo[i].eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].die = 0;
		if (pthread_mutex_init(&philo[i].fork_left, NULL) != 0)
			return(print_error(ERR_CREATE_MUTEX, philo));
		if (i > 0)
			philo[i].fork_right = &philo[i-1].fork_left;
		i++;
	}
	if (i >= 1)
		philo[0].fork_right = &philo[i].fork_left;
	return (1);
}


int	make_philo(t_data data, t_philo *philo)
{
	int i = 0;

	
	while (i < data.nbr_philo)
	{
		if (pthread_create(&philo[i].tid, NULL, routine, &philo[i]) != 0)
			return (print_error(ERR_CREATE_PHILO, philo));
		i++;
	}
	return (1);
}

int les_enfants_sont_au_park(t_data *data)
{
	
	long i = 0;
	while(1)
	{
		printf("%ld coucou\n", data->nbr_philo);
		while (i < data->nbr_philo)
		{
			if(data->nbr_philo == 666)
				return(1);
			i++;
		}
		if(i == data->nbr_philo)
			i = 0;
	
	}
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

	init_data(argc, argv, &data);
	philo = malloc(sizeof(t_philo) * data.nbr_philo);
	if (!philo)
		return (print_error(ERR_MALLOC, philo));
//	if (!check_error(argc, &data, philo))
//		return (0);
	if (!init_philo(&data, philo))
		return (0);
	if (!make_philo(data, philo))
		return (0);	
	if (les_enfants_sont_au_park(&data) == 1)
		return (EXIT_SUCCESS);
}
