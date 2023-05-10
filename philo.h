/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:57:00 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/10 16:31:54 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo
{
	int			meals;
	int			position;
	int			left_fork;
	int			right_fork;
	int 		last_meal;
}t_philo;

typedef struct s_data
{
	pthread_t		*philo_id;
	int				nbr_meals;
	int				nbr_philo;
	int				dead;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}t_data;

void	exit_error(char *msg);
int		ft_atoi(const char *str);

#endif