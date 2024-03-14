/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:29:14 by shmuhamm          #+#    #+#             */
/*   Updated: 2024/02/26 17:32:05 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** ANSI Escape Sequences for Bold Text Colors
** Usage: 
**     printf(R "This is red text." RST);
**     printf(B "This is blue text." RST);
** Remember to use RST to reset the color after setting it.
*/

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define G "\033[1;32m"   /* Bold Green */
# define Y "\033[1;33m"   /* Bold Yellow */
# define B "\033[1;34m"   /* Bold Blue */
# define M "\033[1;35m"   /* Bold Magenta */
# define C "\033[1;36m"   /* Bold Cyan */
# define W "\033[1;37m"   /* Bold White */

typedef struct s_philos
{
	int				id;
	int				fork_r;
	int				fork_l;
	long long		last_meal;
	pthread_t		thread;
	struct s_data	*data;
}					t_philos;

typedef struct s_data
{
	int				n_philos;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		num_to_eat;
	int				end_game;
	t_philos		*t_philos;
	pthread_mutex_t	num_meals_locker;
	pthread_mutex_t	last_meals_locker;
	pthread_mutex_t	end_g;
	pthread_mutex_t	*fork_locker;
	int				*fork;
}					t_data;
/*parsing*/
void				parse_input(char **args);
int					ft_atoi(const char *nptr);
void				error_exit(const char *error);
void				*ft_calloc(size_t count, size_t size);
/*Data_init*/
void				init_data(int ac, char **av, t_data *data);
/*utils*/
long long			timestamp(void);
void				launch_philo(t_data *data);
#endif
