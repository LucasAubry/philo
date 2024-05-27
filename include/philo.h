/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:11 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/27 13:39:59 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

/* =========== INCLUDE ============= */

# include "pthread.h"
# include "unistd.h"


/* ========== STRUCTURE ============= */

typedef strucut s_list
{
	struct s_data *data;
	pthread_t	tid;
	struct s_philo *next;
} t_list;


typedef struct s_data
{
	long		nbr_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_of_meals;
} t_data;


typedef struct s_philo
{
	pthread_t	tid;
	int	eat;
	int	sleep;
	int	think;
	int	die;
	int fork left;
	int fork *right;

	struct *s_data;
}t_philo;

// ./philo 20 500 200 200
//
//	
//	000 : start
//	050 : philo 4 f g
//	052 : philo 4 f d
// 	200 : philo 4 is eating
//
/* =========== Error ================*/

# define ERROR_CREATE_PHILO 0


/* ========= FONCTION ============== */

//tools :
long	ft_atoi(char *str);



#endif
