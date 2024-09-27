# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 16:47:31 by dramos-j          #+#    #+#              #
#    Updated: 2024/09/08 16:47:31 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf
MLX = ./minilibx-linux/libmlx.a
MLX_DIR = ./minilibx-linux
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext
SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		main.c init.c checkers.c clean.c validate_map.c \
		save_map.c utils.c draw_map.c play_game.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
