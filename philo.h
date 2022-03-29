/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@students.42wolfsburg.de>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:52:49 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/29 07:41:32 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo {
	int					id;
	int					l_fork;
	int					r_fork;
	int					eaten_meals;
	long long			last_meal_time;
	pthread_t			thrd_id;
	struct s_data		*info;
}				t_philo;

typedef struct s_data {
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						min_meals;
	int						meal_flag;
	int						end;
	long long				start_time;
	pthread_mutex_t			eat_mtx;
	pthread_mutex_t			sleep_mtx;
	pthread_mutex_t			think_mtx;
	int						nbr_of_philos;
	struct s_philo			*philo;
}				t_data;

void *function();
int init_philos(t_data *info, char **argv);
int init_table(t_data *info);
long long	get_time(void);

#endif