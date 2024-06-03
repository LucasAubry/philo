#include "philo.h"

void	lock_unlock_fork(t_philo *philo, int i)
{
	if (i == 1) // lock
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->fork_left);
			print_philo(philo, "has taken a fork left\n");
			pthread_mutex_lock(philo->fork_right);	
			print_philo(philo, "has taken a fork right\n");
		}
		else
		{
			pthread_mutex_lock(philo->fork_right);
			print_philo(philo, "has taken a fork right\n");
			pthread_mutex_lock(&philo->fork_left);
			print_philo(philo, "has taken a fork left\n");
		}
	}
	else if (i == 0)// unlock
	{
		pthread_mutex_unlock(&philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
}

void	is_eating(t_philo *philo)
{
	lock_unlock_fork(philo, 1);
	//temp
	print_philo(philo, "is eating\n");
	philo->nbr_of_eat += 1;
	usleep(philo->data->time_to_eat * 1000);
	lock_unlock_fork(philo, 0);
}

void	is_thinking(t_philo *philo)
{
	print_philo(philo, "is thinking\n");
}

void	is_sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping\n");	
	usleep(philo->data->time_to_sleep * 1000);
	is_thinking(philo);
}

void	*routine (void *buff)
{
	t_philo *philo = (t_philo *)buff;
	
	while(philo->data->die != 1 && philo->nbr_of_eat < philo->data->nbr_of_meals)
	{	
		is_eating(philo);
		is_sleeping(philo);
	//	printf("philo[%d] : nbr_eat = %d, nbr_meals = %ld", philo->id, philo->nbr_of_eat, philo->data->nbr_of_meals);
	//	printf("     %d", philo->nbr_of_eat <= philo->data->nbr_of_meals);
	}
	philo->is_ok = 0;
	return (NULL);
}

