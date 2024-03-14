/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:22:56 by shmuhamm          #+#    #+#             */
/*   Updated: 2024/03/14 15:17:46 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->t_philos)
	{
		data->t_philos[i].data = data;
		data->t_philos[i].id = i + 1;
		data->t_philos[i].last_meal = timestamp();
		data->t_philos[i].fork_r = i;
		if (data->n_philos > 1)
			data->t_philos[i].fork_l = (i + 1) % data->n_philos;
		pthread_mutex_init(&data->fork_locker, NULL);
	}
}

void	init_data(int ac, char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->num_to_eat = 0;
	data->end_game = 0;
	if (ac == 6)
		data->num_to_eat = ft_atoi(av[5]);
	if (data->n_philos <= 0 || data->t_die <= 0 || data->t_eat <= 0
		|| data->t_sleep <= 0 || data->num_to_eat < 0)
	{
		free(data);
		error_exit("Invalid Arguments");
	}
	data->t_philos = ft_calloc(data->n_philos, sizeof(t_philos));
	pthread_mutex_init(&data->num_meals_locker, NULL);
	pthread_mutex_init(&data->last_meals_locker, NULL);
	pthread_mutex_init(&data->end_g, NULL);
	data->fork = ft_calloc(data->n_philos, sizeof(int));
	data->fork = ft_calloc(data->n_philos, sizeof(pthread_mutex_t));
	init_philos(data);
}

void	launch_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&data->t_philos[i].thread, NULL, &philo_life,
				&(data->t_philos[i])) != 0)
			return ;
	}
}
