/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:20:50 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/12 14:56:53 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_data(t_data *data, char **argv, int argc)
{
    data->nbr_philo = ft_atoi(argv[1]);
    data->philo_id = malloc(sizeof(pthread_t) * data->nbr_philo);
    if (!data->philo_id)
        exit_error("alloc memory philo failed\n");
    
}