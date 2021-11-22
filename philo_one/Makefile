# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 00:56:42 by hcanon            #+#    #+#              #
#    Updated: 2020/10/15 12:06:37 by mmaj             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#====================================OBJS=======================================
OBJS_GEN		=	${SRCS_GEN:.c=.o}



#====================================SRCS=======================================
SRCS_GEN		=	srcs/main.c					\
					srcs/lib.c					\
					srcs/print.c				\
					srcs/philo_monitoring.c		\
					srcs/philo_routine.c		\
					srcs/philo_actions.c		\
					srcs/philo_utils.c			\
					srcs/init_philo.c

#=============================FLAGS AND COMPILERS===============================
CC				=	gcc -g3
CFLAGS			=	-Wall -Wextra -Werror -pthread -I ${HEADER}
CFLAGS_TEST		=	-fsanitize=address
NAME			=	philo_one
HEADER			=	./includes/


#================================AVAILABLE RULES================================
#-----
$(NAME):	all

#-----
all:		${OBJS_GEN}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS_GEN}

#-----
clean:
		rm -f ${OBJS_GEN}

#-----
fclean:		clean
		rm -f ${NAME}

#-----
re:		fclean ${NAME}

#-----
.PHONY:		all clean fclean re test
