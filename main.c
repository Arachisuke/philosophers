/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:41:30 by wzeraig           #+#    #+#             */
/*   Updated: 2024/08/31 15:29:53 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philos[PHILO_MAX];

	Parsing_input(argc, argv);
	init_data(argc, argv, &data, &philos);
}
void	init_data(int argc, char **argv, t_data *data, t_philo *philo)
{
	
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->dead_flag = 0;
	data->philos = philo;
}
void	init_philo(int argc, char **argv, t_data *data, t_philo *philo)
{
	int i;

	i = 0;

	while(i < ft_atoii(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].last_meal = 0;
		init_input(argc, argv, philo[i]);
	}
}

void init_input(int argc, char *argv, t_philo philo)
{
	philo.num_of_philos = ft_atoii(argv[1]);
	philo.time_to_eat = ft_atoii(argv[3]);
	philo.time_to_sleep = ft_atoii(argv[4]);
	philo.time_to_die = ft_atoii(argv[2]);
	if (argv[5])
		philo.num_times_to_eat = ft_atoii(argv[5]);
	else
		philo.num_of_philos = -1;

}

size_t get_time(void)
{
	struct tm time;

	if (gettimeofday())
}
