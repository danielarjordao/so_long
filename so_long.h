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

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit;
	int		collectibles;
	int		collectibles_collected;
	int		moves;
}	t_map;

typedef struct s_textures
{
	void	*walls;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_textures;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_textures	*textures;
	t_map	*map;
}	t_data;

// init.c
void	init_data(t_data *data);
int		init_map(char *file, t_map *map);
char	**init_line(char **file, t_map *map);

// clean.c
void	free_array(char **array);
void	destroy_textures(t_data *data);
void	handle_close(t_data *data);
int		close_window(t_data *data);

// validate_map.c
int		validate_map(char *file, t_data *data);

// checkers.c
int	check_extension(char *file);
int		check_wall(char *line);
int		check_map_content(char *line, t_map *map, int n_line);
int	check_reachable(t_data *data);
int	is_acessible(t_data *data, char **temp_map, int x, int y);

// utils.c
int		count_lines(char *file);
char	**copy_map(char **map, int rows);

// save_map.c
void	add_wall(int row, int col, t_map *map);
void	add_collectible(int row, int col, t_map *map);
void	add_exit(int row, int col, t_map *map);
void	add_player(int row, int col, t_map *map);
void	add_floor(int row, int col, t_map *map);

// load_textures.c
void	load_textures(t_data *data);

// draw_map.c
void	draw_map(t_data *data);
void	put_textures(t_data *data, t_map *map);
void	put_player(t_data *data, t_map *map, t_textures *textures);

// move_player.c
int		key_press(int keycode, t_data *data);
void	walk(t_data *data, int next_y, int next_x);

#endif
