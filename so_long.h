/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:13:52 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/30 19:13:52 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	int		movements;
	int		collectibles_collected;
	int		exits_reached;
	int		**collectibles_pos;
	int		**exits_pos;
}	t_map;

// main.c
void	color_screen(t_data *data, int color);
int		key_press(int keycode, void *param);
int		close_window(t_data *data);
void	free_array(char **array);
void	free_map(t_map *map);

// validate_map.c
int		check_extension(char *file);
int		count_lines(char *file);
int		check_wall(char *line);
int	check_map_content(char *line, size_t len, int n_line, t_map *map);
int		check_map(char *file, t_map *map);

// map_utils.c
int	init_map(char *file, t_map *map, char ***line, int *n_lines, int *fd, int *len);
void	handle_error(int fd, char **line, t_map *map);

// create_map.c
void	add_wall(int row, int col, t_map *map);
void	add_collectible(int row, int col, t_map *map);
void	add_exit(int row, int col, t_map *map);
void	add_player(int row, int col, t_map *map);
void	add_floor(int row, int col, t_map *map);

#endif
