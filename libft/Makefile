# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 13:44:54 by xli               #+#    #+#              #
#    Updated: 2021/04/10 12:31:10 by yfu              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c

BONUS_SRCS =	ft_minmax.c

HEADER = libft.h

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME):$(OBJS) $(BONUS_OBJS)
		@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

all:	$(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
		@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
		@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
		@rm -rf $(NAME)

re:		clean all

.PHONY:	all clean fcl re
