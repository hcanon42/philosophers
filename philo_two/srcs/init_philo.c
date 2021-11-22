/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/12/17 09:51:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

pthread_t			ft_new_philo(int i)
{
	pthread_t		thread;
	int				err;

	usleep(35);
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

void				ft_sem_init(void)
{
	sem_unlink("Forks");
	if (!(g_philo.forks =
		sem_open("Forks", O_CREAT, 0660, g_philo.number_of_philo + 1)))
		exit(-1);
	sem_unlink("Printer");
	if (!(g_philo.printer = sem_open("Printer", O_CREAT, 0660, 1)))
		exit(-1);
	sem_unlink("Death");
	if (!(g_philo.death = sem_open("Death", O_CREAT, 0660, 1)))
		exit(-1);
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
