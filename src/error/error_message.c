#include "philo.h"

void	print_message(char *s)
{
	int	i = -1;

	while (s[i++])
		write(2, &s[i], 1);
}

int	print_error(int code_error, t_philo *philo)
{
	if (code_error == ERR_CREATE_PHILO)
		print_message(MSG_CREATE_PHILO);
	else if (code_error == ERR_CREATE_MUTEX)
		print_message(MSG_CREATE_MUTEX);
	else if (code_error == ERR_MALLOC)
		print_message(MSG_MALLOC);
	else if (code_error == ERR_NBR_PHILO)
		print_message(MSG_NBR_PHILO);
	else if (code_error == ERR_TIME_TO_DIE_NO_EAT_TO_SHORT)
		print_message(MSG_TIME_TO_DIE_NO_EAT_TO_SHORT);
	else if (code_error == ERR_TOO_MANY_PHILO)
		print_message(MSG_TOO_MANY_PHILO);
	else if (code_error == ERR_TO_DIE_NO_EAT_TO_LONG)
		print_message(MSG_TO_DIE_NO_EAT_TO_LONG);
	else if (code_error == ERR_TIME_TO_SLEEP_TO_LONG)
		print_message(MSG_TIME_TO_SLEEP_TO_LONG);
	else if (code_error == ERR_TIME_TO_EAT_TO_SHORT)
		print_message(MSG_TIME_TO_EAT_TO_SHORT);
	else if (code_error == ERR_TIME_TO_SLEEP_TO_SHORT)
		print_message(MSG_TIME_TO_SLEEP_TO_SHORT);
	free_all(philo);
	return (1);
}
