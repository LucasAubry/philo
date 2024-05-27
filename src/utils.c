#include "philo.h"

long	ft_atol(char *str)
{
	long			i;
	long			j;
	long long		n;

	i = 0;
	j = 1;
	n = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (j * n);
}
