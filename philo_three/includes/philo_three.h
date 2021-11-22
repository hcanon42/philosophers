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

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

typedef struct			s_philo
{
	pid_t				*philosophers;
	unsigned int		number_of_philo;
	unsigned long		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					number_of_meals;
	int					stop;
	unsigned long		base_time;
	unsigned long		*last_meal;
	sem_t				*forks;
	sem_t				*death;
	sem_t				*printer;
	sem_t				*meals;
}						t_philo;

t_philo					g_philo;

void					*intern_monitoring(void *num);
void					*ft_routine(void *num);
void					ft_drop_forks(void);
void					ft_sem_init(void);
void					ft_free_philo(void);
void					ft_genocide(void);
void					ft_exit_philo(int nb_meals, int nb);
void					ft_putchar(char c);
void					ft_putstr_fd(char *str, int fd);
void					ft_recur(unsigned long nb);
void					ft_wait_end(void);
void					ft_free_sem(void);
int						ft_strlen(char *str);
int						check_input(int ac, char **av);
int						ft_isdigit(char c);
int						ft_atoi(char *str);
int						ft_print_message(int nb, char *str, int type);
int						ft_sleep(int nb);
int						ft_eat(int nb);
int						ft_take_forks(int nb);
int						ft_init_philo(int ac, char **av);
int						ft_stop(void);
int						ft_philo(int ac, char **av);
unsigned long			get_time(void);
pid_t					ft_new_philo(int i);

#endif
