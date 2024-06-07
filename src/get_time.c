/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:58 by laubry            #+#    #+#             */
/*   Updated: 2024/06/06 00:34:11 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// long	get_time(void)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

//SOURCE DU PROBLEME A REGLER DEMAIN GROS CON
long	get_time(struct timeval	start_time)
{
	static struct timeval	end_time;
	long					seconds;
	long					micro;

	gettimeofday(&end_time, NULL);
	seconds = end_time.tv_sec - start_time.tv_sec;
	micro = end_time.tv_usec - start_time.tv_usec;
	return ((seconds * 1000) + (micro / 1000));
}
// gettimeofday(&data->time_start, NULL);
