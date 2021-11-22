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

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void		ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	i--;
	while (ft_isdigit(str[++i]) == 1)
		nb = nb * 10 + str[i] - 48;
	return (sign * nb);
}

int			check_input(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] == '+')
			j++;
		if (av[i][j] == 0)
			return (-1);
		while (av[i][j])
			if (ft_isdigit(av[i][j++]) == 0)
				return (-1);
	}
	return (0);
}
