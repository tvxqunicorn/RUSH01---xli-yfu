# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 21:41:31 by xli               #+#    #+#              #
#    Updated: 2021/04/09 22:20:56 by xli              ###   ########lyon.fr    #
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

$(NAME): $(OBJS)
		make -C $(LIB)libft
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all : $(NAME)

clean :
	make clean -C $(LIB)libft
	rm -rf $(OBJS)

fclean :
	make fclean -C $(LIB)libft
	rm -rf $(OBJS)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re
