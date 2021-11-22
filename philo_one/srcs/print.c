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

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_recur(unsigned long nb)
{
	if (nb / 10 > 0)
		ft_recur(nb / 10);
	ft_putchar((char)((nb % 10) + 48));
}

int					ft_print_message(int nb, char *str, int type)
{
	pthread_mutex_lock(&g_philo.printer);
	if (ft_stop() == -1 && type == 0)
	{
		pthread_mutex_unlock(&g_philo.printer);
		return (-1);
	}
	ft_recur(get_time());
	ft_putstr_fd(" --- ", 1);
	ft_recur((unsigned long)nb);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(&g_philo.printer);
	return (0);
}
