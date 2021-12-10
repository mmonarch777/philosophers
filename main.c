/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:55:47 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/10 19:24:45 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arguments(int argc, char **argv, int i, int j)
{
	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (1);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_check_death(void *ddate)
{
	t_date	*date;
	int		i;
	int		eat;

	date = (t_date *)ddate;
	while (1)
	{
		eat = 0;
		i = -1;
		usleep(100);
		while (++i < date->nb)
		{
			if (get_time(date->phil[i].eat) > date->time_die)
			{
				pthread_mutex_lock(&date->write);
				printf("%d %d died\n", get_time(date->start), date->phil[i].id);
				return (NULL);
			}
			if (date->phil[i].count_eat == date->nb_eat && date->nb_eat != -1)
				eat++;
			if (date->nb == eat)
				return (NULL);
		}
	}
}

void	finish(t_date *date)
{
	pthread_join(date->death, NULL);
	free(date->fork);
	free(date->phil);
}

int	main(int argc, char **argv)
{
	t_date		date;
	int			i;

	if (ft_check_arguments(argc, argv, 0, 0))
	{
		ft_error("Error argv. Please give me:\n1.Number philo <= 200\n"
			"2.Time dia\n3.Time eat\n4.Time sleep\n5.Number times to eat");
		return (1);
	}
	if (ft_init(argv, &date))
	{
		ft_error("Error initialization");
		return (1);
	}
	i = -1;
	while (++i < date.nb)
	{
		pthread_create(&(date.phil[i].ph), NULL, death_diner, &(date.phil[i]));
		pthread_detach(date.phil[i].ph);
	}
	pthread_create(&date.death, NULL, ft_check_death, &date);
	finish(&date);
	return (0);
}
