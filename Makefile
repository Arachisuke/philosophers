# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 13:41:01 by ahbey             #+#    #+#              #
#    Updated: 2024/09/09 14:00:21 by wzeraig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  parsing.c\
		check_arg.c\
		init.c\
		routine.c\
		main.c\

CC	=	cc

CFLAGS	=	-g -Wall -Wextra -Werror -pthread

OBJS	=	$(SRCS:.c=.o)

NAME	=	philo


all: ${NAME}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c philo.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re/