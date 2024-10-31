/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:21:09 by macos             #+#    #+#             */
/*   Updated: 2024/09/09 14:23:59 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_the_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten == philo->num_times_to_eat)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	pthread_mutex_lock(philo->write_lock);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "has taken a fork");
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten == philo->num_times_to_eat)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_lock(philo->write_lock);
	ft_print(philo, "is eating");
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten == philo->num_times_to_eat)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->write_lock);
	ft_print(philo, "is sleeping");
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten == philo->num_times_to_eat)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	usleep(360);
	pthread_mutex_lock(philo->write_lock);
	ft_print(philo, "is thinking");
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

void	init_forks(char **argv, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoii(argv[1]))
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
