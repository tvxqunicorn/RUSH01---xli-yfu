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

CFLAGS = -Wall -Wextra -Werror -I includes -fsanitize=address -g

SRCS = ./srcs/main.c ./srcs/parse.c

HEADER = ./includes/

INCLUDE = ./includes/ofc.h

LIB = libft/

LIBFLAGS = -L $(LIB) -lft

OBJS = $(SRCS:.c=.o)

$(NAME): $(INCLUDE) $(OBJS) $(SRCS)
		make -C $(LIB)
		$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

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
