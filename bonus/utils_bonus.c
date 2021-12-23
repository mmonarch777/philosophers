/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:06:53 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/23 15:07:19 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	sleeping(t_date *date)
{
	sem_wait(date->write);
	printf("%d %d is sleeping\n", get_time(date->start), date->id);
	sem_post(date->write);
	time_eat_sleep_think(date->t_sleep);
}

void	thinking(t_date *date)
{
	sem_wait(date->write);
	printf("%d %d is thinking\n", get_time(date->start), date->id);
	sem_post(date->write);
	usleep(100);
}
