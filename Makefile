# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 21:41:31 by xli               #+#    #+#              #
#    Updated: 2021/04/09 23:25:24 by xli              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = rush

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes -g

SRCS = ./srcs/main.c ./srcs/parse.c	./srcs/ft_minmax.c

HEADER = ./includes/

INCLUDE = ./includes/ofc.h

OBJS = $(SRCS:.c=.o)

$(NAME): $(INCLUDE) $(OBJS) $(SRCS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re
