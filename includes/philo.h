/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:57:00 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/18 18:44:22 by crtorres         ###   ########.fr       */
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
	int				meals;
	int				id;
	int				position;
	int				left_fork;
	int				right_fork;
	int 			count_meal;
	int 			last_meal;
	int 			status;
	int				eating;
	unsigned long	tt_die;
	pthread_mutex_t	lock;
	struct s_data	*st_data;
}t_philo;

typedef struct s_data
{
	pthread_t		*philo_id;
	int				nbr_meals;
	int				nbr_philo;
	int				dead;
	int				end;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}t_data;

void	exit_error(char *msg);
int		ft_atoi(const char *str);
int		ft_init_data(t_data *data, int argc, char **argv);
int		ft_create_philo(t_data *data);
int		ft_create_forks(t_data *data);

#endif