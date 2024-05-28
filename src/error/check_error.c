/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:51:46 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/05/28 06:48:13 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	check_error_2(int argc, char **argv)
{
	(void)argc;
	if (argv[3] <= 0)
	{
		printf("le temps pour mager est trop court");
		return (0);
	}
	if (argv[4] <= 0)
	{
		printf("le temps pour dormire est trop long");
		return (0);
	}
	return (1);
}

int	check_error_max(int argc, char **argv)
{
	(void)argc;
	if (argv[1] > 200)
	{
		printf("il y a trop de philo");
		return (0);
	}
	if (argv[2] > INT_MAX)
	{
		printf("le temps pour pour mourire sans manger est trop long");
		return (0);
	}
	if (argv[3] > INT_MAX)
	{
		printf("le temps pour manger est trop long");
		return (0);
	}
	if (argv[4] > INT_MAX)
	{
		printf("le temps pour dormir est trop long");
		return (0);
	}
	return (1);
}

int	check_error(int argc, char **argv)
{

	if (argc != 5 || argc != 6)
	{
		printf("les arguments ne sont pas bons");
		return (0);
	}
	if (argv[1] <= 0)
	{
		printf("il n'y a pas de philo");
		return (0);
	}
	if (argv[2] <= 0)
	{
		printf("le temps pour mourir sans mager est trop court");
		return (0);
	}
	if (check_error_2(argc, argv) == 0)
			return (0);
	if (check_error_max(argc, argv) == 0)
		return (0);
	return (1);
}
