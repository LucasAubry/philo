/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:20:27 by laubry            #+#    #+#             */
/*   Updated: 2024/06/03 15:18:04 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *s)
{
	int	i = 0;

	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	print_error(int code_error)
{
	if (code_error == ERR_ARGS)
		print_message("ERREUR D'ARGUMENTS");
	else if (code_error == ERR_MALLOC)
		print_message("ERREUR MALLOC");
	else if (code_error == ERR_CREATE_MUTEX)
		print_message("ERREUR MUTEX");
	else if (code_error == ERR_CREATE_PHILO)
		print_message("ERREUR PHILO");
	else if (code_error == ERR_TOO_PHILO)
		print_message("ERREUR TROP DE PHILO");
	else
		return (0);
	return (1);
}

int	print_philo_eat_all(t_philo *philo)
{
	printf("les philos on bien manger les gros gourmands\n");
	free_all(philo);
	return (1);
}
int	print_philo_is_dead(t_philo *philo, int i)
{
	printf("le philo[%d] vient de mourir (le con)\n", i);
	free_all(philo);
	return (1);
}

void	print_philo(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("the philo[%d] %s", philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

