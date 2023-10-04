/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:56:18 by crtorres          #+#    #+#             */
/*   Updated: 2023/10/04 15:48:52 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_create_threads(t_data *data, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		ft_init_mutex(data, i);
		if (!ft_create_philo(data, argc, argv, i))
			exit_error("failed create philos\n", data);
		pthread_create(&(data->philo_id[i]), NULL, routine, &(data->philos[i]));
	}
	return (0);
}

void	end_subprocesses(t_data *data)
{
	int	i;

	data->nbr_philos_eat = 0;
	while (1)
	{
		i = -1;
		while (++i < data->nbr_philo)
		{
			pthread_mutex_lock(data->philos[i].lock);
			if (!check_death(data, i))
				return ;
			pthread_mutex_unlock(data->philos[i].lock);
		}
	}
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		exit_without_free("invalid number of arguments\n");
	j = 0;
	while (++j < argc)
	{
		i = -1;
		while (argv[j][++i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				exit_without_free("invalid type of argument\n");
		}
	}
	if (!ft_atoi(argv[2]) || !ft_atoi(argv[3])
		|| !ft_atoi(argv[4]))
		exit_without_free("invalid arguments\n");
	if (argc == 6)
		if (!ft_atoi(argv[5]))
			exit_without_free("invalid arguments\n");
	return (0);
}
/* void	ft_leaks()
{
	system("leaks -q philo");
	atexit(ft_leaks);
} */

int	main(int argc, char **argv)
{
	t_data	data;

	data.end = 0;
	ft_check_args(argc, argv);
	if (ft_init_data(&data, argv))
		return (1);
	ft_create_threads(&data, argc, argv);
	end_subprocesses(&data);
	end_philos(&data);
	return (0);
}
