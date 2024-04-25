/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:11 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/04/17 10:23:29 by lucasaubry       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

# include <pthread.h>

typedef strucut s_list
{
	struct s_data *data;
	pthread_t	tid;
	struct s_philo *next;
} t_list;


typedef struct s_data
{
	pthread_t	*tid;
	int			philo_num;
} t_data;
