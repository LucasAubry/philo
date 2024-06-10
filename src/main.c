/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/06/10 17:14:18 by laubry           ###   ########.fr       */
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
	data->philo_eat_all = 0;
	gettimeofday(&data->time_start, NULL);
	if (argc == 6)
		data->nbr_of_meals = ft_atol(argv[5]);
	else
		data->nbr_of_meals = -1;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->meal, NULL);
}

int	monophilo(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->fork_left);
	print_philo(philo, "has taken a fork left\n");
	usleep(philo->data->time_to_die * 1000);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld le philo[%d] vient de mourir (le con)\n",
		get_time(philo->data->time_start), i);
	pthread_mutex_unlock(&philo->data->print);
	free_all(philo);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	i = -1;
	if (!new_error(argc, argv))
		return (0);
	init_data(argc, argv, &data);
	if (!error_advanced(data))
		return (0);
	philo = malloc(sizeof(t_philo) * data.nbr_philo);
	if (!init_philo(&data, philo))
	{
		free(philo);
		return (0);
	}
	if (data.nbr_philo == 1)
		return (monophilo(philo));
	if (!make_philo(data, philo))
		return (free_all(philo));
	while (if_is_end(&data, philo) == 0)
		usleep(100);
	while (++i < data.nbr_philo)
		pthread_join(philo[i].tid, NULL);
	return (free_all(philo));
}
