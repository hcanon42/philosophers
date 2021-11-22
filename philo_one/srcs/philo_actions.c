/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/09/04 14:58:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int					ft_take_forks(int nb)
{
	if (nb == 0)
		pthread_mutex_lock(&g_philo.mutex[g_philo.number_of_philo - 1]);
	else
		pthread_mutex_lock(&g_philo.mutex[nb - 1]);
	if (ft_print_message(nb + 1, " has taken a fork\n", 0) == -1)
		return (-1);
	pthread_mutex_lock(&g_philo.mutex[nb]);
	if (ft_print_message(nb + 1, " has taken a fork\n", 0) == -1)
		return (-1);
	return (0);
}

void				ft_drop_forks(int nb)
{
	if (nb == 0)
		pthread_mutex_unlock(&g_philo.mutex[g_philo.number_of_philo - 1]);
	else
		pthread_mutex_unlock(&g_philo.mutex[nb - 1]);
	pthread_mutex_unlock(&g_philo.mutex[nb]);
}

int					ft_eat(int nb)
{
	unsigned long	start;
	unsigned long	obj;

	obj = g_philo.time_to_eat;
	if (ft_take_forks(nb) == -1 ||
		ft_print_message(nb + 1, " is eating\n", 0) == -1)
	{
		ft_drop_forks(nb);
		return (-1);
	}
	g_philo.last_meal[nb] = get_time();
	start = get_time();
	while (get_time() - start < obj)
	{
		if (ft_stop() == -1)
		{
			ft_drop_forks(nb);
			return (-1);
		}
		usleep(100);
	}
	ft_drop_forks(nb);
	return (0);
}

int					ft_sleep(int nb)
{
	unsigned long	start;
	unsigned long	obj;

	obj = g_philo.time_to_sleep;
	if (ft_print_message(nb + 1, " is sleeping\n", 0) == -1)
		return (-1);
	start = get_time();
	while (get_time() - start < obj)
	{
		if (ft_stop() == -1)
			return (-1);
		usleep(100);
	}
	return (0);
}
