/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:50:33 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/12 15:11:12 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

unsigned long	get_time(void)
{
	struct timeval	tm;

	if (gettimeofday(&tm, NULL))
		return (exit_error);
	return ((tm.tv_sec * (unsigned long)1000) + (tm.tv_usec / 1000));
}

void	ft_clear_data(t_data *data)
{
	if (data->philo_id)
		free(data->philo_id);
	if (data->forks)
		free(data->forks);
	if (data->nbr_philo)
		free(data->nbr_philo);
}

int	ft_usleep(useconds_t time)
{
	unsigned long	start;

	start = get_time();
	while (get_time - start <= time)
		usleep(time/10);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	j;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((sign * j) > 2147483647 || (sign * j) < -2147483648)
		exit_error("error\n");
	return (sign * j);
}