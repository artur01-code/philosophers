/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@students.42wolfsburg.de>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:21:07 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/29 08:06:02 by jtomala          ###   ########.fr       */
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
    while (!ph->info->end)
    {
        if (ph->info->meal_flag && ph->eaten_meals == ph->info->min_meals)
        {
            write(1, "%lld philo[%d] ate all meals\n", 25);
            return (0);
        }
        //check_death(ph);
        //grab_fork(ph);
    }
    return (0);
}

int init_table(t_data *info)
{
    int i;

    i = 0;
    while (i < info->nbr_of_philos)
    {
        info->philo[i].last_meal_time = get_time();
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
    if (info->end == 1)
        //lock_all(info);
    return (0);
}

int init_philos(t_data *info, char **argv)
{
    int i;
    
    i = 0;
    info->nbr_of_philos = atoi(argv[1]);
    info->time_to_die = atoi(argv[2]);
    info->time_to_eat = atoi(argv[3]);
    info->time_to_sleep = atoi(argv[4]);
    info->start_time = get_time();
    info->end = 0;
    if (argv[5])
        info->min_meals = atoi(argv[5]);
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

    if (argc < 5 || argc > 6)
    {
        write(1, "Invalid argument\n", 17);
        return (1);
    }
    if (init_philos(&info, argv))
    {
        //clean_table(&info);
        return (0);
    }
    if (init_table(&info))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    //init_table(&info);
    //clean_table(&info);
    return (0);
}