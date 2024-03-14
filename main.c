/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:30:50 by shmuhamm          #+#    #+#             */
/*   Updated: 2024/02/26 17:31:03 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		parse_input(av);
		data = ft_calloc(1, sizeof(t_data));
		init_data(ac, av, data);
		launch_philo(data);
	}
	else
	{
		printf(RED "Wrong arguments\n" RST);
		printf(G "Ex: ./philo [num of philo] [time 2 die] [time 2 eat]" RST);
	}
}
