/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:11 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/30 20:53:49 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

/* =========== INCLUDE ============= */

# include "pthread.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"

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
	int			die;
	pthread_mutex_t print;
}	t_data;


typedef struct s_philo
{
	pthread_t	tid;
	int	id;
	int	eat;
	int	sleep;
	int	think;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	struct s_data *data;

}	t_philo;

/* =========== Error ================*/

# define ERR_ARGS 1
# define ERR_MALLOC 2
# define ERR_CREATE_MUTEX 3
# define ERR_CREATE_PHILO 4
# define ERR_TOO_PHILO 5

/* ========= FONCTION ============== */

//tools :
long	ft_atol(char *str);
void	*routine(void *buff);
void	free_all(t_philo *philo);
int	ft_strlen(char *str);

//int	check_error(int argc, t_data *data, t_philo *philo);
void	print_str(char *str);
int if_is_dead(t_data *data, t_philo *philo);
int	print_philo_is_dead(t_philo *philo, int i);
void	print_philo(t_philo *philo, char *str);


int	new_error(int argc, char **argv);
int	print_error(int code_error);
int	error_advanced(t_data data);


//philo :
int	make_philo(t_data data, t_philo *philo);
int	if_is_dead(t_data *data, t_philo *philo);
int	init_philo(t_data *data, t_philo *philo);

#endif
