/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:10:54 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/23 17:09:46 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = pointer;
	philo->tt_die = philo->st_data->death_time + get_time();
	
}

void	*supervisor(void *pointer)
{
	t_philo *philo;
	unsigned long	time;
	
	philo = pointer;
	time = philo->st_data->start_time;
	while (philo->st_data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->tt_die && philo->eating == 0)
		{
			pthread_mutex_lock(&philo->st_data->write);
			if (philo->st_data->dead == 0)
			{
				printf("%ld %d is died\n", time, philo->id);
			}
		}
	}
}

