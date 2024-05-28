/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:11 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/28 06:50:45 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

/* =========== INCLUDE ============= */

# include "pthread.h"
# include "unistd.h"
# include "stdlib.h"

/* ========== STRUCTURE ============= */

typedef struct s_list
{
	struct s_data *data;
	pthread_t	tid;
	struct s_philo *next;
}	t_list;


typedef struct s_data
{
	long		nbr_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_of_meals;
}	t_data;


typedef struct s_philo
{
	pthread_t	tid;
	int	id;
	int	eat;
	int	sleep;
	int	think;
	int	die;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	struct s_data *data;

}	t_philo;

/* =========== Error ================*/

# define ERROR_CREATE_PHILO 0
# define ERROR_CREATE_MUTEX 0
# define ERROR_MALLOC 0

/* ========= FONCTION ============== */

//tools :
long	ft_atol(char *str);
int	print_error(int code_error, t_philo *philo);
void	*routine(void *buff);
void	free_all(t_philo *philo);
int	check_error(int argc, char **argv);

#endif
