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

int					main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd((char *)"Error: wrong number of arguments\n", 2);
		return (-1);
	}
	if (check_input(ac, av) == -1)
	{
		ft_putstr_fd((char *)"Error: wrong usage of arguments\n", 2);
		return (-1);
	}
	if (ft_philo(ac, av) == -1)
	{
		ft_putstr_fd("Error during initialization of philosophers\n", 2);
		return (-1);
	}
	return (0);
}
