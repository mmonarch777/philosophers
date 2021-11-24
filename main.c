/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:55:47 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/24 16:17:27 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arguments(int argc, char **argv, int i, int j)
{
	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
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
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
//	pthread_t	check_death;
	t_date		date;
	int			i;

	if (ft_check_arguments(argc, argv, 0, 0))
	{
		ft_error("Error argv. Please give me:\n1.Number philo\n"
			"2.Time dia\n3.Time eat\n4.Time sleep\n5.Number times to eat");
		return (1);
	}
	if (ft_init(argv, &date))
	{
		ft_error("Error initialization\n");
		return (1);
	}
	i = 0;
	while (i < date.nb)
	{
		pthread_create(&(date.phil[i].ph), NULL, ft_death_dinner, &(date.phil[i]));
		usleep(1);
		i++;
	}
	sleep(10);
	return (0);
}
