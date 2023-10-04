/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:28:31 by crtorres          #+#    #+#             */
/*   Updated: 2023/10/04 15:47:11 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_data(t_data *data, char **argv)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->philos = malloc(sizeof(t_philo) * (data->nbr_philo));
	if (!data->philos)
		return (exit_error("failed to alloc memory philosopher\n", data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->forks)
		return (exit_error("failed to alloc memory forks\n", data));
	data->lock = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->lock)
		return (exit_error("failed to alloc lock memory", data));
	data->print_lock = malloc(sizeof(pthread_mutex_t) * 1);
	if (!data->print_lock)
		return (exit_error("failed to alloc print_lock memory", data));
	data->philo_id = malloc(sizeof(pthread_t) * data->nbr_philo);
	if (!data->philo_id)
		return (exit_error("failed to alloc philo_id memory", data));
	data->end = 0;
	data->init_time = get_time();
	if (data->nbr_philo <= 0 || data->nbr_philo > 200)
		return (exit_error("invalid input data\n", data));
	return (0);
}

int	ft_init_mutex(t_data *data, int i)
{
	if (pthread_mutex_init(&(data->forks[i]), NULL))
		return (exit_error("failed init mutex\n", data));
	if (pthread_mutex_init(&(data->lock[i]), NULL))
		return (exit_error("failure to init mutex\n", data));
	if (pthread_mutex_init(&(data->print_lock[i]), NULL))
		return (exit_error("failure to init mutex\n", data));
	return (0);
}

int	ft_create_philo(t_data *data, int argc, char **argv, int i)
{
	data->philos[i].n_meals = 0;
	data->philos[i].all_meals = 0;
	data->philos[i].death_time = ft_atoi(argv[2]);
	data->philos[i].eat_time = ft_atoi(argv[3]);
	data->philos[i].sleep_time = ft_atoi(argv[4]);
	data->philos[i].start_time = data->init_time;
	data->philos[i].st_data = data;
	data->philos[i].id = i + 1;
	data->philos[i].end = &(data->end);
	data->philos[i].left_fork = i;
	data->philos[i].right_fork = (i + 1) % (data->nbr_philo);
	data->philos[i].lock = &(data->lock[i]);
	data->philos[i].print_lock = data->print_lock;
	data->philos[i].last_meal = 0;
	if (argc == 6)
	data->philos[i].max_meals = ft_atoi(argv[5]);
	else
		data->philos[i].max_meals = -1;
	return (1);
}
