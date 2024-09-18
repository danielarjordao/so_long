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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
	int		width;
	int		height;
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

typedef struct s_texture
{
	void	*walls;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_texture;

// main.c
int		key_press(int keycode, void *param);
int		close_window(t_data *data);
void	free_array(char **array);
void	free_map(t_map *map);

// validate_map.c
int		check_extension(char *file);
int		count_lines(char *file);
int		check_wall(char *line);
int		check_map_content(char *line, size_t len, int n_line, t_map *map);
int		check_map(char *file, t_map *map);

// map_utils.c
int		init_map(char *file, t_map *map, char ***line, int *fd);
void	handle_error(int fd, char **line, t_map *map);

// create_map.c
void	add_wall(int row, int col, t_map *map);
void	add_collectible(int row, int col, t_map *map);
void	add_exit(int row, int col, t_map *map);
void	add_player(int row, int col, t_map *map);
void	add_floor(int row, int col, t_map *map);

// define_textures.c
void	define_textures(t_texture *texture, t_data *data);

// draw_map.c
void	draw_map(t_data *data, t_map *map, t_texture *texture);
void	put_textures(t_data *data, t_map *map, t_texture *texture);
void	put_player(t_data *data, t_map *map, t_texture *texture);
void	put_collectibles(t_data *data, t_map *map, t_texture *texture);
void	put_exit(t_data *data, t_map *map, t_texture *texture);


#endif
