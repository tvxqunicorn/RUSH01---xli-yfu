# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 21:41:31 by xli               #+#    #+#              #
#    Updated: 2021/04/14 15:21:01 by yfu              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = rush

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = ./srcs/main.c

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
