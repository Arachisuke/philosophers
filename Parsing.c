/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:38:47 by wzeraig           #+#    #+#             */
/*   Updated: 2024/08/28 15:25:57 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	Parsing_input(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		ft_error(argc, argv);
	checkarg(argc, argv);
	if (ft_atoii(argv[1]) > 200)
		ft_error(argc, argv);
	if (ft_atoii(argv[2]) < 0)
		ft_error(argc, argv);
	if (ft_atoii(argv[3]) < 0)
		ft_error(argc, argv);
	if (ft_atoii(argv[4]) < 0)
		ft_error(argc, argv);
}

void	ft_error(int argc, char **argv)
{
	exit(0);
}