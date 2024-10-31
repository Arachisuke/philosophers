/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:03:01 by wzeraig           #+#    #+#             */
/*   Updated: 2024/09/08 18:38:59 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **argv, t_data *data, t_philo *philo)
{
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->dead_flag = 0;
	data->philos = philo;
	data->argv_copy = argv[1];
}

void	init_philo(char **argv, t_data *data, t_philo *philo,
		pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoii(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
		init_input(argv, &philo[i]);
		philo[i].start_time = get_time();
		philo[i].last_meal = get_time();
		philo[i].dead_lock = &data->dead_lock;
		philo[i].meal_lock = &data->meal_lock;
		philo[i].write_lock = &data->write_lock;
		philo[i].dead = &data->dead_flag;
		philo[i].l_fork = &forks[i];
		philo[i].argv_copy = argv[1];
		if (i == 0)
			philo[i].r_fork = &forks[philo->num_of_philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_input(char **argv, t_philo *philo)
{
	philo->num_of_philos = ft_atoii((const char *)argv[1]);
	philo->time_to_eat = ft_atoii((const char *)argv[3]);
	philo->time_to_sleep = ft_atoii((const char *)argv[4]);
	philo->time_to_die = ft_atoii((const char *)argv[2]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoii(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

int	ft_print(t_philo *philo, char *str)
{
	int	i;

	if (*philo->dead)
	{
		return (1);
	}
	i = 0;
	if (str)
		printf("%ld %d %s\n", get_time() - philo->start_time, philo->id, str);
	return (0);
}

void	destroy_all_mutex(t_data *data, char **argv, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoii(argv[1]))
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
}
