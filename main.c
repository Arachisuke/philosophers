/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:00:15 by wzeraig           #+#    #+#             */
/*   Updated: 2024/09/09 14:00:39 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(150);
	if (philo->id == philo->num_of_philos && philo->num_of_philos % 2 != 0)
		usleep(150);
	while (1)
	{
		if (take_the_fork(philo))
			break ;
		if (ft_eat(philo))
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		if (ft_sleep(philo))
			break ;
		if (philo->num_of_philos != philo->id)
			ft_think(philo);
	}
	return (NULL);
}

int	are_u_dead(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (1)
	{
		while (++i < ft_atoii(data->argv_copy))
		{
			if (count(philo))
				return (1);
			pthread_mutex_lock(philo->meal_lock);
			if (get_time() - philo[i].last_meal >= philo->time_to_die)
			{
				pthread_mutex_unlock(philo->meal_lock);
				pthread_mutex_lock(&data->write_lock);
				pthread_mutex_lock(&data->dead_lock);
				ft_print(philo, "died");
				data->dead_flag = 1;
				pthread_mutex_unlock(&data->dead_lock);
				pthread_mutex_unlock(&data->write_lock);
				return (1);
			}
			pthread_mutex_unlock(philo->meal_lock);
		}
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	fork[PHILO_MAX];
	t_data			data;
	t_philo			philo[PHILO_MAX];

	if (parsing_input(argc, argv))
		return (0);
	data.philos = philo;
	init_data(argv, &data, data.philos);
	init_forks(argv, fork);
	init_philo(argv, &data, data.philos, fork);
	if (philo->num_of_philos == 1)
		ft_alone(philo);
	else
	{
		if (thread_create(&data, philo))
			return (1);
	}
	destroy_all_mutex(&data, argv, fork);
}

int	thread_create(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoii(data->argv_copy))
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			return (1);
		i++;
	}
	are_u_dead(data, philo);
	i = 0;
	while (i < ft_atoii(data->argv_copy))
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
