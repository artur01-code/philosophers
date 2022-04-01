/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:00:11 by jtomala           #+#    #+#             */
/*   Updated: 2022/04/01 13:18:55 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *ph)
{
	long long	curr;

	curr = get_time();
	if (curr - ph->last_meal_time > ph->info->time_to_die)
		ph->info->end = 1;
}

void	ft_sleep(t_philo *ph, int time_to_sleep)
{
	pthread_mutex_lock(&(ph->info->sleep_mtx));
	printf("%lld Philo[%d] is sleeping\n", get_time() \
		- ph->info->start_time, ph->id);
	usleep(time_to_sleep);
	check_death(ph);
	pthread_mutex_unlock(&(ph->info->sleep_mtx));
}

void	eat(t_philo *ph, int time_to_eat)
{
	check_death(ph);
	ph->last_meal_time = get_time();
	pthread_mutex_lock(&(ph->info->eat_mtx));
	printf("%lld Philo[%d] is eating\n", get_time() \
		- ph->info->start_time, ph->id);
	usleep(time_to_eat);
	check_death(ph);
	ph->eaten_meals++;
	pthread_mutex_unlock(&(ph->info->eat_mtx));
}

void	grab_fork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->l_fork]));
	printf("%lld Philo[%d] has taken left fork\n", get_time() \
		- ph->info->start_time, ph->id);
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->r_fork]));
	printf("%lld Philo[%d] has taken right fork\n", get_time() \
		- ph->info->start_time, ph->id);
	eat(ph, ph->info->time_to_eat);
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->l_fork]));
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->r_fork]));
	ft_sleep(ph, ph->info->time_to_sleep);
	printf("%lld Philo[%d] is thinking\n", get_time() \
		- ph->info->start_time, ph->id);
}
