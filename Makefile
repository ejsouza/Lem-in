# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 09:20:47 by esouza            #+#    #+#              #
#    Updated: 2019/02/26 09:49:14 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBFT = libft

SRC_DIR = src

CC = gcc -Iincludes/lem_in.h

FLAGS = -Wall -Werror -Wextra

SRCS = ./src/main.c \
       ./src/parser.c \
       ./src/look_for_ants.c \
       ./src/rooms.c \
       ./src/path.c \
       ./src/which_command.c \
       ./src/free_center.c \
       ./src/create_matrix.c \
       ./src/set_index.c \
       ./src/algorithm.c \
       ./src/queue.c \
       ./src/breadth_first_search.c \
       ./src/print.c \

OBJS = $(SRCS:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT)

$(NAME) : $(OBJS) Makefile
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	@echo "\033[0;32m	Executable $(NAME) created"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@rm -f $(OBJS)
	@cd src rm %.o

fclean :
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re libft

