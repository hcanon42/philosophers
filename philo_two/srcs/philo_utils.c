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

#include "philo_two.h"

void				ft_free_philo(void)
{
	int		i;

	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		pthread_detach(g_philo.philosophers[i]);
	sem_unlink("Printer");
	sem_close(g_philo.printer);
	sem_unlink("Forks");
	sem_close(g_philo.forks);
	sem_unlink("Death");
	sem_close(g_philo.death);
	free(g_philo.philosophers);
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
	sem_wait(g_philo.death);
	if (g_philo.stop == 1)
	{
		sem_post(g_philo.death);
		return (-1);
	}
	sem_post(g_philo.death);
	return (0);
}
