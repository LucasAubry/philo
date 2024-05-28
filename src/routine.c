#include "philo.h"

void	*routine (void *buff)
{
	t_philo *philo = (t_philo *)buff;
	(void)philo;

	while(1)
	{
	//penser
		write(1, "P", 1);
	//	pthread_mutex_lock(&philo->forck_left);
		//usleep(philo->data->time_to_think * 1000);

		//prend la fourchette
	//	pthread_mutex_lock(&philo->fork_left);
	//	pthread_mutex_lock(philo->fork_right);


	//	//manger
	//	write(1, "M", 1);
	//	usleep(philo->data->time_to_eat * 1000);

	//	//depose la fourchette
	//	pthread_mutex_unlock(&philo->fork_left);
	//	pthread_mutex_unlock(philo->fork_right);

	//	//dort
	//	write(1, "D", 1);
	//	usleep(philo->data->time_to_sleep * 1000);
	}

	return(NULL);
}

