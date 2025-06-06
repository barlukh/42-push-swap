# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 11:21:03 by bgazur            #+#    #+#              #
#    Updated: 2025/05/31 15:11:25 by bgazur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRCS:.c=.o)
SRCS =	ft_main.c \
		ft_operations_multiple.c \
		ft_operations_single.c \
		ft_parse_input_utils.c \
		ft_parse_input.c \
		ft_sort_utils.c \
		ft_sort.c \
		ft_split_utils.c \
		ft_split.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
