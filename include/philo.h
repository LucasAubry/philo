/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:11 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/29 17:08:06 by laubry           ###   ########.fr       */
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

/*--------------obligatoir--------------*/


/*-------------a voir si obligatoir ----*/

# define ERR_CREATE_PHILO 1
# define MSG_CREATE_PHILO "erreur create philo\n"
# define ERR_CREATE_MUTEX 2
# define MSG_CREATE_MUTEX "erreur create mutex\n"
# define ERR_MALLOC 3
# define MSG_MALLOC "erreur malloc\n"
# define ERR_NBR_PHILO 4
# define MSG_NBR_PHILO "erreur nombre de philo\n"
# define ERR_TIME_TO_DIE_NO_EAT_TO_SHORT 5
# define MSG_TIME_TO_DIE_NO_EAT_TO_SHORT "erreur temps pour mager est trop court\n"
# define ERR_TOO_MANY_PHILO 6
# define MSG_TOO_MANY_PHILO "erreur trop de philo\n"
# define ERR_TO_DIE_NO_EAT_TO_LONG 7
# define MSG_TO_DIE_NO_EAT_TO_LONG "erreur le temps sans manger est trop long\n"
# define ERR_TIME_TO_SLEEP_TO_LONG 8
# define MSG_TIME_TO_SLEEP_TO_LONG "erreur le temps pour dormir est trop long\n"
# define ERR_TIME_TO_SLEEP_TO_SHORT 9
# define MSG_TIME_TO_SLEEP_TO_SHORT "erreur le temps pour dormir est trop court\n"
# define ERR_TIME_TO_EAT_TO_LONG 10
# define MSG_TIME_TO_EAT_TO_LONG "erreur le temps pour manger est trop long\n"
# define ERR_ARGS 11
# define MSG_ARGS "erreur le nombres d'arguement n'est pas bon\n"
# define ERR_TIME_TO_EAT_TO_SHORT 12
# define MSG_TIME_TO_EAT_TO_SHORT "erreur le temps pour manger est trop court\n" 

/* ========= FONCTION ============== */

//tools :
long	ft_atol(char *str);
int	print_error(int code_error, t_philo *philo);
void	*routine(void *buff);
void	free_all(t_philo *philo);
//int	check_error(int argc, t_data *data, t_philo *philo);
void	print_str(char *str);
int if_is_dead(t_data *data, t_philo *philo);
int	print_philo_is_dead(t_philo *philo, int i);
void	print_philo(t_philo *philo, char *str);

#endif
