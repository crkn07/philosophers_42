/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:56:18 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/16 12:13:19 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

ft_init(t_data *data, int argc, char **argv)
{
	ft_init_data(data, argc, argv);
	
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 5 || argc > 6)
		exit_error("invalid number of arguments\n");
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				return (ft_atoi(argv[j]));
			else
				exit_error("invalid type of argument\n");
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_check_args(argc, argv);
	ft_init(&data, argc, argv);	
}