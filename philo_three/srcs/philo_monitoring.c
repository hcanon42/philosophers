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

void				*check_death(void *param)
{
	(void)param;
	sem_wait(g_philo.death);
	g_philo.stop = 1;
	return (NULL);
}

void				*check_meals(void *param)
{
	int		i;

	(void)param;
	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		sem_wait(g_philo.meals);
	g_philo.number_of_meals = -2;
	return (NULL);
}

void				ft_wait_end(void)
{
	pthread_t		died;
	pthread_t		meals;

	pthread_create(&died, NULL, check_death, NULL);
	pthread_create(&meals, NULL, check_meals, NULL);
	while (1)
	{
		if (g_philo.stop == 1)
		{
			ft_genocide();
			g_philo.number_of_meals = -2;
			break ;
		}
		if (g_philo.number_of_meals == -2)
		{
			sem_post(g_philo.death);
			break ;
		}
	}
	pthread_join(died, NULL);
	pthread_join(meals, NULL);
}

void				ft_genocide(void)
{
	int				i;

	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		kill(g_philo.philosophers[i], SIGINT);
	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		sem_post(g_philo.meals);
	usleep(1000 * 1001);
}

int					ft_philo(int ac, char **av)
{
	int		i;

	if (ft_init_philo(ac, av) == -1)
		return (-1);
	ft_sem_init();
	usleep(1500);
	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		g_philo.philosophers[i] = ft_new_philo(i);
	ft_wait_end();
	ft_free_philo();
	ft_free_sem();
	return (0);
}
