# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 12:05:29 by mdella-r          #+#    #+#              #
#    Updated: 2024/05/18 10:50:27 by mdella-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = color.c formula.c fractol.c hook.c render.c switch.c utils.c
OBJS = $(SRCS:.c=.o)
INCLUDES = .
HEADERS = fractol.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = fractol
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
		@git clone $(MLX_REPO) $(MLX_DIR)
		@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -I$(MLX_DIR) -lXext -lX11 -lm -lz -lpthread -O3 -o $(NAME)
		@echo compiled $(NAME)

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@echo removed object files

fclean: clean
		@$(RM) $(NAME)
		@echo removed $(NAME)

re: fclean all

.PHONY: all clean fclean re