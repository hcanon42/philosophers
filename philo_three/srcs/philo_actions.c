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

#include "philo_three.h"

int					ft_take_forks(int nb)
{
	sem_wait(g_philo.forks);
	if (ft_print_message(nb + 1, " has taken a fork\n", 0) == -1)
		return (-1);
	sem_wait(g_philo.forks);
	if (ft_print_message(nb + 1, " has taken a fork\n", 0) == -1)
		return (-1);
	return (0);
}

void				ft_drop_forks(void)
{
	sem_post(g_philo.forks);
	sem_post(g_philo.forks);
}

int					ft_eat(int nb)
{
	unsigned long	start;
	unsigned long	obj;

	obj = g_philo.time_to_eat;
	if (ft_take_forks(nb) == -1 ||
		ft_print_message(nb + 1, " is eating\n", 0) == -1)
	{
		ft_drop_forks();
		return (-1);
	}
	g_philo.last_meal[nb] = get_time();
	start = get_time();
	while (get_time() - start < obj)
	{
		if (ft_stop() == -1)
		{
			ft_drop_forks();
			return (-1);
		}
		usleep(100);
	}
	ft_drop_forks();
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
