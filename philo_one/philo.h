/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:52:49 by jtomala           #+#    #+#             */
/*   Updated: 2022/04/01 16:10:30 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

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
	int						nbr_of_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						min_meals;
	int						meal_flag;
	int						end;
	long long				start_time;
	pthread_mutex_t			eat_mtx;
	pthread_mutex_t			sleep_mtx;
	pthread_mutex_t			*fork_mtx;
	t_philo					*philo;
}				t_data;

void		*function();
int			init_datas(t_data *info, char **argv);
int			init_philos(t_data *info);
int			init_table(t_data *info);
long long	get_time(void);
void		grab_fork(t_philo *ph);
void		eat(t_philo *ph);
void		ft_sleep(t_philo *ph);
int			check_death(t_philo *ph);
void		lock_all(t_philo *ph);
void		clean_table(t_data *data);
int			ft_atoi(const char *str);
int			check_args(t_data *info);
int			handle_one(t_data *info);

#endif