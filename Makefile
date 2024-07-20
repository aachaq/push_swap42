# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachaq <aachaq@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 00:01:33 by aachaq            #+#    #+#              #
#    Updated: 2022/12/11 21:36:44 by aachaq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = push_swap.c push_swap_utile.c check_error.c instruction.c \
	instruction2.c function.c index.c push_swap_utile2.c big_sort_function.c\
	big_sort_function2.c big_sort_utile.c

SRCS_BONUS = checker.c checker_utils.c check_error.c\
	push_swap_utile.c instruction.c instruction2.c get_next_line.c\
	get_next_line_utils.c function.c  push_swap_utile2.c index.c\
	big_sort_function.c big_sort_utile.c big_sort_function2.c 

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all
