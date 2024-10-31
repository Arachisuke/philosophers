/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:39:01 by wzeraig           #+#    #+#             */
/*   Updated: 2024/09/08 18:40:05 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define PHILO_MAX 200
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"
# define PEACH "\033[38;5;217m"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	char			*argv_copy;

}					t_philo;
typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	char			*argv_copy;
	t_philo			*philos;
}					t_data;

int					parsing_input(int argc, char **argv);
int					checkarg(int argc, char **argv);
void				init_data(char **argv, t_data *data, t_philo *philo);
void				init_philo(char **argv, t_data *data, t_philo *philo,
						pthread_mutex_t *forks);
int					ft_atoii(const char *str);
void				init_forks(char **argv, pthread_mutex_t *forks);

size_t				get_time(void);
void				init_input(char **argv, t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					ft_think(t_philo *philo);
int					ft_print(t_philo *philo, char *str);
int					are_u_dead(t_data *data, t_philo *philo);
int					take_the_fork(t_philo *philo);
int					count(t_philo *philo);
void				destroy_all_mutex(t_data *data, char **argv,
						pthread_mutex_t *forks);
void				ft_alone(t_philo *philo);
int					thread_create(t_data *data, t_philo *philo);

#endif