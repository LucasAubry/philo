/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/27 14:07:24 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#incude "philo.h"

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
	data->is_die = 0;
//	data->tid = malloc(sizeof(pthread_t) * data->nbr_philo);
}

void init_philo(int argc, char **argv, t_data *data, t_philo *philo)
{
	unsigned int i = 0;

	while (i < data->nbr_philo)
	{
		philo[i].eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].die = 0;
		if (pthread_mutex_init(&philo[i].fork_left, NULL) != 0)
			return (print_error(ERROR_CREATE_MUTEX));
		if (i > 0)
			philo[i].fork_right = &philo[i--].fork_left;
		i++;
	}
	if (i >= 1)
		philo[0].fork_right = &philo[i].fork_left;
}

void *routine (void *buff)
{
	t_data *data;
	data = (t_data *)buff;
}


int	make_philo(t_data data, t_list **philo_list)
{
	int i = 0;

	while (i < data->nbr_philo)
	{
		if (pthread_create(&philos[i].tid, NULL, routine, &philos[i]) != 0)
			return (print_error(ERROR_CREATE_PHILO));
		i++;
	}
}


//argv[1] = nbr de philo et nbr de fourchettes 200
//argv[2] = temps avant de mourrire sans manger en millisecondes int max
//argv[3] = temps pour manger en millisecondes int max
//argv[4] = temps pour dormir em millisecondes int max
//argv[5](optionelle) = nombre de repas que les philos doivent faire int max

int	main(int argc, char **argv)
{
	t_list *list;
	t_data data;
	check_error(argc, argv);
	init_data(argc, argv, &data);
	if (!make_philo(argv, list))
		return (0);
}
