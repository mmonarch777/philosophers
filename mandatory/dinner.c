/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:43:41 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/20 17:11:32 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_first(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&(date->fork[philo->left_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d taken a l_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&(date->fork[philo->right_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d taken a r_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&date->write);
	if (get_time(date->phil->eat) > date->time_die)
	{
		pthread_mutex_unlock(&date->write);
		sleep(1);
	}
	printf("%d %d is eating\n", get_time(date->start), philo->id);
	gettimeofday(&philo->eat, NULL);
	pthread_mutex_unlock(&date->write);
	time_eat_sleep_think(date->time_eat);
	if (date->nb_eat != -1)
		philo->count_eat++;
	pthread_mutex_unlock(&(date->fork[philo->left_fork]));
	pthread_mutex_unlock(&(date->fork[philo->right_fork]));
}

void	ft_eat_second(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&(date->fork[philo->right_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d taken a r_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&(date->fork[philo->left_fork]));
	pthread_mutex_lock(&date->write);
	printf("%d %d taken a l_fork\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	pthread_mutex_lock(&date->write);
	if (get_time(date->phil->eat) > date->time_die)
	{
		pthread_mutex_unlock(&date->write);
		sleep(1);
	}
	printf("%d %d is eating\n", get_time(date->start), philo->id);
	gettimeofday(&philo->eat, NULL);
	pthread_mutex_unlock(&date->write);
	time_eat_sleep_think(date->time_eat);
	if (date->nb_eat != -1)
		philo->count_eat++;
	pthread_mutex_unlock(&(date->fork[philo->right_fork]));
	pthread_mutex_unlock(&(date->fork[philo->left_fork]));
}

void	*dinner(void *philo_date)
{
	t_philo	*philo;
	t_date	*date;

	philo = (t_philo *)philo_date;
	date = philo->date;
	if (!(philo->id % 2))
		usleep(2000);
	while (1)
	{
		if (philo->id % 2)
			ft_eat_first(philo, date);
		else
			ft_eat_second(philo, date);
		if (date->nb_eat != -1 && date->nb_eat == philo->count_eat)
			break ;
		sleeping(philo, date);
		thinking(philo, date);
	}
	return (0);
}
