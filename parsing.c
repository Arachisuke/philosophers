/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:38:47 by wzeraig           #+#    #+#             */
/*   Updated: 2024/09/08 18:12:29 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_input(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		return (1);
	if (checkarg(argc, argv))
		return (1);
	if (ft_atoii(argv[1]) > 200 || ft_atoii(argv[1]) < 1)
		return (1);
	if (ft_atoii(argv[2]) <= 0)
		return (1);
	if (ft_atoii(argv[3]) <= 0)
		return (1);
	if (ft_atoii(argv[4]) <= 0)
		return (1);
	if (argv[5])
		if (ft_atoii(argv[5]) <= 0)
			return (1);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	count(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoii(philo->argv_copy))
	{
		pthread_mutex_lock(philo->meal_lock);
		if (philo[i].meals_eaten != philo[i].num_times_to_eat)
		{
			pthread_mutex_unlock(philo->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	return (1);
}

void	ft_alone(t_philo *philo)
{
	ft_print(philo, "has taken a fork");
	while (1)
	{
		if (get_time() - philo->last_meal >= philo->time_to_die)
		{
			printf("%ld   %d %s\n", philo->time_to_die, philo->id, "died");
			return ;
		}
	}
	return ;
}
