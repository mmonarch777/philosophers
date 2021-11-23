#include "philo.h"
#include <stdio.h>

int	get_time(struct timeval time)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	now.tv_sec -= time.tv_sec;
	now.tv_usec -= time.tv_usec;
	if (now.tv_usec < 0)
	{
		now.tv_sec--;
		now.tv_usec += 1000000;
	}
	return (int)(now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_eat_first(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&(date->fork[philo->right_fork]));
	pthread_mutex_lock(&date->write);
	(void)date;
	printf("   %d\n", philo->id);
	philo->count_eat++;
	printf("counter first %d\n", philo->count_eat);
	usleep(5000);
}

void	ft_eat_second(t_philo *philo)
{
	printf("%d\n", philo->id);
	philo->count_eat++;
	printf("counter %d\n", philo->count_eat);
	usleep(5000);
}

void	*ft_death_dinner(void *philo_date)
{
	t_philo	*philo;
	t_date 	*date;

	philo = (t_philo *)philo_date;
	date = philo->date;
	if (philo->id % 2)
		sleep (1);
	while (1)
	{
		if (!(philo->id % 2))
			ft_eat_first(philo, date);
		else
			ft_eat_second(philo);
		if (date->number_eat == philo->count_eat)
		{
			printf("finish\n");
			break;
		}
		printf("%d time %d\n", philo->id, get_time(date->start));
	}
	return (0);
}
