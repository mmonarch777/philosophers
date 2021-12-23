/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:06:38 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/23 15:10:07 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include "../libmini/libmini.h"
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_date
{
	int				id;
	int				nb;
	int				t_dia;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				p_nb_eat;
	struct timeval	last_eat;
	sem_t			*fork;
	sem_t			*write;
	pid_t			*ipid;
	struct timeval	start;
}					t_date;

void	go_eat(t_date *date);
int		get_time(struct timeval time);
void	time_eat_sleep_think(int time);
void	sleeping(t_date *date);
void	thinking(t_date *date);

#endif 
