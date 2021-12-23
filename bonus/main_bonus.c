/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:06:26 by mmonarch          #+#    #+#             */
/*   Updated: 2021/12/23 15:37:19 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		if (!argv[i][j])
			return (1);
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

void	ft_init_semophor(t_date *date)
{
	sem_unlink("fork");
	sem_unlink("write");
	date->write = sem_open("write", O_CREAT, 0666, 1);
	date->fork = sem_open("fork", O_CREAT, 0666, date->nb);
}

int	ft_init(char **argv, t_date *date)
{
	gettimeofday(&date->start, NULL);
	gettimeofday(&date->last_eat, NULL);
	date->nb = ft_atoi(argv[1]);
	date->t_dia = ft_atoi(argv[2]);
	date->t_eat = ft_atoi(argv[3]);
	date->t_sleep = ft_atoi(argv[4]);
	date->id = 0;
	date->p_nb_eat = 0;
	date->nb_eat = -1;
	if (argv[5])
	{
		date->nb_eat = ft_atoi(argv[5]);
		if (date->nb_eat == 0)
			exit(0);
	}
	date->ipid = malloc(sizeof (pid_t) * date->nb);
	if (!date->ipid)
		return (1);
	ft_init_semophor(date);
	return (0);
}

void	finish(t_date *date)
{
	int	box;
	int	j;

	box = 0;
	j = 0;
	while (j < date->nb)
	{
		waitpid(0, &box, 0);
		if (box)
		{
			while (j < date->nb)
			{
				kill(date->ipid[j++], SIGTERM);
				break ;
			}
		}
		j++;
		if (j == date->nb && !box)
			printf("%d ALL EAT :)\n", get_time(date->start));
	}
	sem_close(date->write);
	sem_close(date->fork);
	free(date->ipid);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_date	date;
	int		i;

	if (ft_check_arguments(argc, argv, 0, 0))
	{
		ft_error("Error argv. Please give me(type int):\n1.Number philo <= 200\n"
			"2.Time dia\n3.Time eat\n4.Time sleep\n5.Number times to eat");
		return (1);
	}
	if (ft_init(argv, &date))
	{
		ft_error("Error initialization");
		return (1);
	}
	i = 0;
	while (i < date.nb)
	{
		date.id = i + 1;
		date.ipid[i] = fork();
		if (date.ipid[i] == 0)
			go_eat(&date);
		i++;
	}
	finish(&date);
}
