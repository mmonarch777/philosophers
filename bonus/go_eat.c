/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:06:16 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/23 15:06:20 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_date *date)
{
	sem_wait(date->fork);
	sem_wait(date->fork);
	sem_wait(date->write);
	printf("%d %d taken a r_fork\n", get_time(date->start), date->id);
	printf("%d %d taken a l_fork\n", get_time(date->start), date->id);
	sem_post(date->write);
	sem_wait(date->write);
	printf("%d %d is eating\n", get_time(date->start), date->id);
	gettimeofday(&date->last_eat, NULL);
	sem_post(date->write);
	time_eat_sleep_think(date->t_eat);
	if (date->nb_eat != -1)
		date->p_nb_eat++;
	sem_post(date->fork);
	sem_post(date->fork);
}

void	*check(void *date_p)
{
	t_date	*date;

	date = (t_date *) date_p;
	while (1)
	{
		if (get_time(date->last_eat) > date->t_dia)
		{
			sem_wait(date->write);
			printf("%d %d is dia\n", get_time(date->start), date->id);
			break ;
		}
		usleep(500);
	}
	exit(1);
}

void	go_eat(t_date *date)
{
	pthread_t	death;

	pthread_create(&death, NULL, check, date);
	pthread_detach(death);
	while (1)
	{
		eat(date);
		if (date->nb_eat == date->p_nb_eat && date->nb_eat != -1)
			break ;
		sleeping(date);
		thinking(date);
	}
	exit(0);
}
