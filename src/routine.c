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
	usleep(philo->data->time_to_eat * 1000);
	lock_unlock_fork(philo, 0);
}

void	is_sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping\n");	
	usleep(philo->data->time_to_sleep * 1000);
}

void	is_thinking(t_philo *philo)
{
	print_philo(philo, "is thinking\n");
}

void	*routine (void *buff)
{
	t_philo *philo = (t_philo *)buff;
	
	while(philo->data->die != 1)
	{	
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

