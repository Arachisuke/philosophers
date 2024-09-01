/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:21:09 by macos             #+#    #+#             */
/*   Updated: 2024/09/01 20:23:47 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routine(void *arg)
{
    t_data *data = (t_data *)arg; // je dois le mettre en pointeur si je veux changer les variables ? dans la routine je change rien de toute maniere mais je lenverrais en pointeur au fonction par contre 
    while(1 || data->philos->meals_eaten)
    if (data->philos->id % 2 != 0)
        usleep(10000); // le temps de time of eat ? ou assez de temps juste pour etre sur que chaque thread pair est passe
    if (data->philos->id == data->philos->num_of_philos && data->philos->num_of_philos % 2 != 0)
        usleep(1000);
    pthread_mutex_lock(data->philos->l_fork); // je lock la droite et la gauche mtn ya que les pair qui rentre car jai bien attendu tout les pair darrive pour lock donc les impair on pas pu lock avant
    pthread_mutex_lock(data->philos->r_fork);
    printf("%d philo %d taking the fork", data->philos->start_time, data->philos->id); // changer le start time et mettre temps actuel du philo
    fonction_eat(&data->philos, &data); // zone a risque
    pthread_mutex_unlock(data->philos->r_fork);
    pthread_mutex_unlock(data->philos->l_fork);
    fonction_sleep(&data->philos, &data);
    if (data->philos->dead == 0)
    {
        printf("philo %d die", data->philos->id);
        return(0);  
    }
    
}

void *fonction_eat(t_philo *philo, t_data *data)
{
    if (philo->dead)
        return(0);
    printf("%d philo %d is eating", philo->start_time, philo->id); // changer le start time et mettre temps actuel du philo
    usleep(philo->time_to_eat);
    
}
void *fonction_sleep(t_philo *philo, t_data *data)
{
    if (philo->dead)
        return(0);
    printf("%d philo %d is sleeping", philo->start_time, philo->id); // changer le start time et mettre temps actuel du philo
    usleep(philo->time_to_sleep);
}

void *fonction_think(t_philo *philo, t_data *data)
{
     if (philo->dead)
        return(0);
    printf("%d philo %d is thinking", philo->start_time, philo->id); // changer le start time et mettre temps actuel du philo
    // calcul du temps de think
}


// oublie pas les changement au niveau du parsing philo 0 meal 0
