/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:21:07 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/28 14:55:13 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> //atoi

void *function(void *philos)
{
    t_philo *ph;
    
    ph = (t_philo *) philos;
    if (ph->id % 2)
        usleep(ph->info->time_to_eat * 500);
    printf("[%lld]: I am philo[%d]: left %d, right %d\n", get_time(), ph->id, ph->l_fork, ph->r_fork);
    return (0);
}

int init_table(t_data *info)
{
    int i;

    i = 0;
    while (i < info->nbr_of_philos)
    {
        if (pthread_create(&(info->philo[i].thrd_id), NULL, \
			&function, (void *)&(info->philo[i])))
            return (1);
        i++;
    }
    i = 0;
    while (i < info->nbr_of_philos)
    {
        if (pthread_join(info->philo[i].thrd_id, NULL) != 0)
            return (1);
        i++;
    }
    return (0);
}

int init_philos(t_data *info)
{
    int i;
    
    i = 0;
    info->philo = malloc(sizeof(t_philo) * info->nbr_of_philos);
    if (!info->philo)
        return (1);
    while (i < info->nbr_of_philos)
    {
        info->philo[i].id = i + 1;
        info->philo[i].l_fork = i;
        info->philo[i].r_fork = (i + 1) % info->nbr_of_philos;
        info->philo[i].eaten_meals = 0;
        info->philo[i].last_meal_time = 0;
        info->philo[i].info = info;
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_data info;

    if (argc != 2)
        return (1);
    info.nbr_of_philos = atoi(argv[1]);
    if (init_philos(&info))
        return (0);
    if (init_table(&info))
        return (0);

    return (0);
}