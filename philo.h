/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:56:01 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/09 16:20:01 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include "libmini/libmini.h"
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		ph;
	int				id;
	int 			right_fork;
	int 			left_fork;
	int 			count_eat;
	int 			death;
	struct s_date	*date;
	struct timeval	eat;
}	t_philo;

typedef struct s_date
{
	int				nb;
	int 			time_die;
	int				time_eat;
	int				time_sleep;
	int 			number_eat;
	t_philo			*phil;
	pthread_mutex_t *fork;
	pthread_mutex_t write;
	pthread_t		death;
	struct timeval	start;

}	t_date;

int		ft_init(char **argv, t_date *date);
void	*ft_death_dinner(void *philo_date);
int		get_time(struct timeval time);
void	time_eat_sleep_think(int time);
void	sleeping(t_philo *philo, t_date *date);
void	thinking(t_philo *philo, t_date *date);

#endif
