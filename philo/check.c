/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:49:09 by jtomala           #+#    #+#             */
/*   Updated: 2022/05/11 08:23:32 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *info)
{
	if (info->time_to_die < 60 || info->time_to_eat < 60 \
		|| info->time_to_sleep < 60 || info->nbr_of_philos > 200)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	read_end(t_philo *ph)
{
	int	red;

	red = 1;
	pthread_mutex_lock(&(ph->info->dies));
	if (ph->info->end == 1)
		red = 0;
	pthread_mutex_unlock(&(ph->info->dies));
	return (red);
}
