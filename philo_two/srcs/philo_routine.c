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

void				ft_exit_philo(int nb_meals, int nb)
{
	if (nb_meals == g_philo.number_of_meals)
	{
		if (ft_print_message(nb + 1,
			" ate his last meal successfully !\n", 0) == -1)
			return ;
		g_philo.last_meal[nb] = 0;
	}
}

void				*ft_routine(void *num)
{
	int				nb;
	int				nb_meals;

	nb = (intptr_t)num;
	nb_meals = 0;
	g_philo.last_meal[nb] = get_time();
	while (ft_stop() == 0)
	{
		ft_print_message(nb + 1, " is thinking\n", 0);
		if (ft_stop() == -1 || ft_eat(nb) == -1)
			break ;
		if ((++nb_meals == g_philo.number_of_meals &&
					g_philo.number_of_meals != -1))
			break ;
		if (ft_stop() == -1 || ft_sleep(nb) == -1)
			break ;
	}
	ft_exit_philo(nb_meals, nb);
	return (NULL);
}
