/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/06/05 18:50:22 by laubry           ###   ########.fr       */
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
	// data->time_start = get_time();
	gettimeofday(&data->time_start, NULL);
	if (argc == 6)
		data->nbr_of_meals = ft_atol(argv[5]);
	else
		data->nbr_of_meals = -1;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
}

//argv[1] = nbr de philo et nbr de fourchettes 200
//argv[2] = temps avant de mourrire sans manger en millisecondes int max
//argv[3] = temps pour manger en millisecondes int max
//argv[4] = temps pour dormir em millisecondes int max
//argv[5](optionelle) = nombre de repas que les philos doivent faire int max

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	philo = NULL;
	i = -1;
	if (new_error(argc, argv))
		return (0);
	init_data(argc, argv, &data);
	if (error_advanced(data))
		return (0);
	philo = malloc(sizeof(t_philo) * data.nbr_philo);
	if (!philo)
		return (print_error(ERR_MALLOC));
	if (!init_philo(&data, philo))
	{
		free(philo);
		return (0);//cree des problemme si le premier mutex ce cree mais pas le deuxieme pour free
	}
	if (!make_philo(data, philo))
		return (free_all(philo));
	while (if_is_end(&data, philo) == 0)
		usleep(100);
	while (++i < data.nbr_philo)
		pthread_join(philo[i].tid, NULL);
	return (free_all(philo));
}
