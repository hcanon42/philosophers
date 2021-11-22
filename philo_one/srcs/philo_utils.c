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

void				ft_free_philo(void)
{
	int		i;

	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		pthread_detach(g_philo.philosophers[i]);
	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		pthread_mutex_destroy(&g_philo.mutex[i]);
	pthread_mutex_destroy(&g_philo.printer);
	pthread_mutex_destroy(&g_philo.death);
	free(g_philo.philosophers);
	free(g_philo.mutex);
	free(g_philo.last_meal);
}

unsigned long		get_time(void)
{
	unsigned long	time;
	struct timeval	time_struct;

	gettimeofday(&time_struct, NULL);
	time = (unsigned long)(time_struct.tv_usec / 1000 +
							time_struct.tv_sec * 1000);
	return (time - g_philo.base_time);
}

int					ft_stop(void)
{
	pthread_mutex_lock(&g_philo.death);
	if (g_philo.stop == 1)
	{
		pthread_mutex_unlock(&g_philo.death);
		return (-1);
	}
	pthread_mutex_unlock(&g_philo.death);
	return (0);
}
