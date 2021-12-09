#include "philo.h"

void	ft_eat_first(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&(date->fork[philo->right_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d has taken a r_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&(date->fork[philo->left_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d has taken a l_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&date->write);
	printf("%d %d is eating\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	if (get_time(philo->eat) > date->time_die)
		philo->death = 1;
	gettimeofday(&philo->eat, NULL);
	if (date->number_eat != -1)
		philo->count_eat++;
	time_eat_sleep_think(date->time_eat);
	pthread_mutex_unlock(&(date->fork[philo->right_fork]));
	pthread_mutex_unlock(&(date->fork[philo->left_fork]));
}

void	ft_eat_second(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&(date->fork[philo->left_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d has taken a r_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&(date->fork[philo->right_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d has taken a l_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&date->write);
	printf("%d %d is eating\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	if (get_time(philo->eat) > date->time_die)
		philo->death = 1;
	gettimeofday(&philo->eat, NULL);
	if (date->number_eat != -1)
		philo->count_eat++;
	time_eat_sleep_think(date->time_eat);
	pthread_mutex_unlock(&(date->fork[philo->right_fork]));
	pthread_mutex_unlock(&(date->fork[philo->left_fork]));
}

void	*ft_death_dinner(void *philo_date)
{
	t_philo	*philo;
	t_date 	*date;

	philo = (t_philo *)philo_date;
	date = philo->date;
	while (1)
	{
		if (!(philo->id % 2))
			ft_eat_first(philo, date);
		else
			ft_eat_second(philo, date);
		if (date->number_eat == philo->count_eat)
		{
			printf("%d %d is FINISH\n", get_time(date->start), philo->id);
			break;
		}
		sleeping(philo, date);
		thinking(philo, date);

	}
	return (0);
}
