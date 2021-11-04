/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:55:47 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/04 19:42:10 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arguments(int argc, char **argv, int i, int j)
{
	if (argc != 5 && argc != 6)
		return (1);
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+')
				j++;
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
	pthread_t	philo;
	t_philo		date;
	static int	i = 0;

	if (ft_check_arguments(argc, argv, 0, 0))
	{
		ft_error("Error. Please give me:\n1.Number philo\n"
			"2.Time dia\n3.Time eat\n4.Time sleep\n5.Number times to eat");
		return (1);
	}
	return (0);
}
