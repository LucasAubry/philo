/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:58 by laubry            #+#    #+#             */
/*   Updated: 2024/06/10 16:27:11 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(struct timeval start_time)
{
	struct timeval			end_time;
	long					seconds;
	long					micro;

	gettimeofday(&end_time, NULL);
	seconds = end_time.tv_sec - start_time.tv_sec;
	micro = end_time.tv_usec - start_time.tv_usec;
	return ((seconds * 1000) + (micro / 1000));
}
