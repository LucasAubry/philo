#include "philo.h"

void	print_message(char *s)
{
	int	i = -1;

	while (s[i++])
		write(2, &s[i], 1);
}

int	print_error(int code_error)
{
	if (code_error == ERROR_CREATE_PHILO)
			print_message(ERROR_CREATE_PHILO);
	else if (code_error == 

	return (0);
}
