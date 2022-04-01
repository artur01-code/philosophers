/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:47:41 by jtomala           #+#    #+#             */
/*   Updated: 2022/04/01 16:13:25 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	lock_all(t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(ph->info->eat_mtx));
	pthread_mutex_lock(&(ph->info->sleep_mtx));
	while (i < ph->info->nbr_of_philos)
	{
		pthread_mutex_destroy(&(ph->info->fork_mtx[ph->l_fork]));
		i++;
	}
	printf("%lld %d died\n", get_time() - ph->info->start_time, ph->id);
}

void	clean_table(t_data *data)
{
	free(data->philo);
	free(data->fork_mtx);
}

int	handle_one(t_data *info)
{
	printf("%lld %d has taken a fork\n", get_time() \
		- info->start_time, info->philo->id);
	usleep(info->time_to_die * 1000);
	 printf("%lld %d died\n", get_time() \
		- info->start_time, info->philo->id);
	return (1);
}
