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
LIBMLX = -I./minilibx-linux -L./minilibx-linux -lmlx -lX11 -lXext -lm -lbsd
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		main.c validate_map.c save_map.c map_utils.c define_textures.c \
		draw_map.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
