/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:26 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/04/17 10:29:27 by lucasaubry       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	make_philo(char **argv, t_list **philo_list)
{

}

void	add_thread(t_list *philo_list, pthread_t pid)
{
	t_list *newnode = (t_list)malloc(sizeof(t_list));
	newnode->tid = tid;
	newnode->next =
}

//argv[1] = nbr de philo et nbr de fourchettes 200
//argv[2] = temps avant de mourrire sans manger en millisecondes int max
//argv[3] = temps pour manger en millisecondes int max
//argv[4] = temps pour dormir em millisecondes int max
//argv[5](optionelle) = nombre de repas que les philos doivent faire int max
int	main(int argc, char **argv)
{
	t_list *philo_list;

	check_error(argc, argv);
	make_philo(argv, &philo);
}
