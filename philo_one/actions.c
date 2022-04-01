/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:00:11 by jtomala           #+#    #+#             */
/*   Updated: 2022/04/01 15:31:44 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *ph)
{
	if (get_time() - ph->last_meal_time > ph->info->time_to_die)
	{
		ph->info->end = 1;
		return (1);
	}
	return (0);
}

void	ft_sleep(t_philo *ph)
{
	long long	curr;

	curr = get_time();
	pthread_mutex_lock(&(ph->info->sleep_mtx));
	printf("%lld %d is sleeping\n", get_time() \
		- ph->info->start_time, ph->id);
	while (get_time() < (curr + ph->info->time_to_sleep) && !check_death(ph))
		usleep(1);
	check_death(ph);
	pthread_mutex_unlock(&(ph->info->sleep_mtx));
}

void	eat(t_philo *ph)
{
	long long	curr;

	curr = get_time();
	pthread_mutex_lock(&(ph->info->eat_mtx));
	check_death(ph);
	ph->last_meal_time = get_time();
	printf("%lld %d is eating\n", get_time() \
		- ph->info->start_time, ph->id);
	while (get_time() < (curr + ph->info->time_to_eat) && !check_death(ph))
		usleep(1);
	pthread_mutex_unlock(&(ph->info->eat_mtx));
	ph->eaten_meals++;
}

void	grab_fork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->l_fork]));
	printf("%lld %d has taken a fork\n", get_time() \
		- ph->info->start_time, ph->id);
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->r_fork]));
	printf("%lld %d has taken a fork\n", get_time() \
		- ph->info->start_time, ph->id);
	eat(ph);
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->l_fork]));
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->r_fork]));
	check_death(ph);
	ft_sleep(ph);
	printf("%lld %d is thinking\n", get_time() \
		- ph->info->start_time, ph->id);
	check_death(ph);
}
