#include "philo.h"

void	delet_mutex(t_philo *philo)
{
	int	i = 0;

	while (i != philo->data->nbr_philo)
	{
		pthread_mutex_destroy(&philo[i].fork_left);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print);
}

void free_all(t_philo *philo)
{
	free(philo);
}
