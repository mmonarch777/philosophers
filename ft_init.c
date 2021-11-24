#include "philo.h"

int	ft_init_philo(t_date *date)
{
	int	i;

	i = 0;
	while (i < date->nb)
	{
		if (pthread_mutex_init(&date->fork[i], NULL))
			return (1);
		gettimeofday(&date->phil[i].eat, NULL);
		date->phil[i].id = i;
		date->phil[i].right_fork = i;
		date->phil[i].count_eat = 0;
		date->phil[i].date = date;
		if (i == date->nb - 1)
			date->phil[i].left_fork = 0;
		else
			date->phil[i].left_fork = i + 1;
//		printf("id %d, right %d, left%d\n", date->phil[i].id, date->phil[i].right_fork, date->phil[i].left_fork);
		i++;
	}
	return (0);
}

int	ft_init(char **argv, t_date *date)
{
	gettimeofday(&date->start, NULL);
	date->nb = ft_atoi(argv[1]);
	date->time_die = ft_atoi(argv[2]);
	date->time_eat = ft_atoi(argv[3]);
	date->time_sleep = ft_atoi(argv[4]);
	date->number_eat = 0;
	if (argv[5])
		date->number_eat = ft_atoi(argv[5]);
	date->phil = malloc(sizeof (t_philo) * date->nb);
	date->fork = malloc(sizeof (pthread_mutex_t) * date->nb);
	if (pthread_mutex_init(&date->write, NULL))
		return (1);
	if (!(date->phil || date->fork))
		return (1);
	if (ft_init_philo(date))
		return (1);
	return (0);
}
