# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 21:41:31 by xli               #+#    #+#              #
#    Updated: 2021/04/09 22:36:08 by xli              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ofc

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = ./srcs/main.c ./srcs/parse.c

HEADER = ./includes/

INCLUDE = ./includes/ofc.h

LIB = libft/

OBJS = $(SRCS:.c=.o)

$(NAME): $(INCLUDE) $(OBJS) $(SRCS)
		make -C $(LIB)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all : $(NAME)

clean :
	make clean -C $(LIB)
	rm -rf $(OBJS)

fclean :
	make fclean -C $(LIB)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re
