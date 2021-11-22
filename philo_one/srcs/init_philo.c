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

pthread_t			ft_new_philo(int i)
{
	pthread_t		thread;
	int				err;

	usleep(50);
	g_philo.last_meal[i] = get_time();
	err = pthread_create(&thread, NULL, ft_routine, (void *)(intptr_t)i);
	if (err != 0)
	{
		ft_putstr_fd("Error during thread creation\n", 2);
		ft_free_philo();
		exit(EXIT_FAILURE);
	}
	return (thread);
}

void				ft_mutex_init(void)
{
	int		i;

	i = -1;
	if (!(g_philo.mutex = malloc(sizeof(*g_philo.mutex) *
							g_philo.number_of_philo)))
		exit(-1);
	while (++i < (int)g_philo.number_of_philo)
		pthread_mutex_init(&g_philo.mutex[i], NULL);
	pthread_mutex_init(&g_philo.printer, NULL);
	pthread_mutex_init(&g_philo.death, NULL);
}

int					ft_init_philo(int ac, char **av)
{
	struct timeval		time;

	if (ft_atoi(av[1]) <= 1)
		return (-1);
	g_philo.number_of_philo = ft_atoi(av[1]);
	g_philo.time_to_die = ft_atoi(av[2]);
	g_philo.time_to_eat = ft_atoi(av[3]);
	g_philo.time_to_sleep = ft_atoi(av[4]);
	g_philo.number_of_meals = -1;
	g_philo.stop = 0;
	if (ac == 6)
		g_philo.number_of_meals = ft_atoi(av[5]);
	if (!(g_philo.philosophers = (pthread_t *)malloc(sizeof(pthread_t) *
								g_philo.number_of_philo)))
		return (-1);
	if (!(g_philo.last_meal = malloc(sizeof(unsigned long) *
								g_philo.number_of_philo)))
		return (-1);
	gettimeofday(&time, NULL);
	g_philo.base_time = (unsigned long)(time.tv_usec / 1000 +
										time.tv_sec * 1000);
	return (0);
}
