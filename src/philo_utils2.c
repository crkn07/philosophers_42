/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:20:50 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/26 16:01:35 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->nbr_philo = (unsigned long)argv[1];
	data->philo_id = malloc(sizeof(pthread_t) * data->nbr_philo);
	if (!data->philo_id)
		exit_error("alloc memory philo_id failed\n");
	data->death_time = (unsigned long)argv[2];
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		exit_error("failed to alloc memory philosopher\n");
	data->eat_time = (unsigned long)argv[3];
	data->sleep_time = (unsigned long)argv[4];
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->forks)
		exit_error("failed to alloc memory forks\n");
	if (argc == 6)
		data->nbr_meals = ft_atoi(argv[5]);
	else
		data->nbr_meals = -1;
	if (data->nbr_philo <= 0 || data->nbr_philo > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		exit_error("invalid input data\n");
	data->dead = 0;
	data->end = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
}

int	ft_create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].st_data = data;
		data->philo[i].id = i + 1;
		data->philo[i].tt_die = data->death_time;
		data->philo[i].count_meal = 0;
		data->philo[i].status = 0;
		data->philo[i].eating = 0;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
}

int	ft_create_forks(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	data->philo[0].left_fork = &data->forks[0];
	data->philo[0].right_fork = &data->forks[data->nbr_philo - 1];
	i = 1;
	while (i < data->nbr_philo)
	{
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[i -1];
		i++;
	}
	return (0);
}