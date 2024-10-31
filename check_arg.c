/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:50:38 by wzeraig           #+#    #+#             */
/*   Updated: 2024/09/08 18:08:00 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkarg(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++j <= argc - 1)
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		i = 0;
	}
	return (0);
}

int	ft_atoii(const char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10);
		res = res + (str[i] - 48);
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (-1);
		i++;
	}
	return (res * sign);
}
