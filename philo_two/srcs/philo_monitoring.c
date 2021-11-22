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

void				ft_wait_end(void)
{
	int				i;
	unsigned int	j;

	while (1)
	{
		i = -1;
		j = 0;
		while (++i < (int)g_philo.number_of_philo)
		{
			if ((long)get_time() - (long)g_philo.last_meal[i] >
			(long)g_philo.time_to_die && (long)g_philo.last_meal[i] != 0)
			{
				ft_genocide(i + 1);
				return ;
			}
			if (g_philo.last_meal[i] == 0)
				j++;
		}
		if (j == g_philo.number_of_philo)
			return ;
	}
}

void				ft_genocide(int nb)
{
	int				i;
	unsigned int	longest;

	sem_wait(g_philo.death);
	g_philo.stop = 1;
	sem_post(g_philo.death);
	ft_print_message(nb, " has died\n", 1);
	i = -1;
	while (++i < (int)g_philo.number_of_philo)
		sem_post(&g_philo.forks[i]);
	if (g_philo.time_to_eat > g_philo.time_to_sleep)
		longest = g_philo.time_to_eat;
	else
		longest = g_philo.time_to_sleep;
	usleep(longest * 1001);
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
	return (0);
}
