/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:20:56 by jtomala           #+#    #+#             */
/*   Updated: 2022/04/01 12:21:08 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

static int	check_calc_value(long res, int c, const char *str)
{
	res = (res * 10) + (str[c] - '0');
	if (res > 2147483647 || res < -2147483648)
		error_exit();
	return ((int) res);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c])
	{
		if (str[c] >= '0' && str[c] <= '9')
			res = check_calc_value(res, c, str);
		else
			error_exit();
		c++;
	}
	return (res * s);
}
