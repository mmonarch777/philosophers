/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:45:29 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/23 14:55:04 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	now.tv_sec -= time.tv_sec;
	now.tv_usec -= time.tv_usec;
	if (now.tv_usec < 0)
	{
		now.tv_sec--;
		now.tv_usec += 1000000;
	}
	return ((int)(now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	time_eat_sleep_think(int time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (get_time(now) < time)
		usleep(200);
}

void	sleeping(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&date->write);
	printf("%d %d is sleeping\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	time_eat_sleep_think(date->time_sleep);
}

void	thinking(t_philo *philo, t_date *date)
{
	pthread_mutex_lock(&date->write);
	printf("%d %d is thinking\n", get_time(date->start), philo->id);
	pthread_mutex_unlock(&date->write);
	usleep(500);
}

void	print(int time, int id, char *str, int len)
{
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, " ", 1);
	write(1, str, len);
}
