/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/18 15:51:45 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	draw_map(t_data *data, t_map *map, t_texture *texture)
{
	define_textures(texture, data);
	put_textures(data, map, texture);
	put_player(data, map, texture);
	put_collectibles(data, map, texture);
	put_exit(data, map, texture);
}

void	put_textures(t_data *data, t_map *map, t_texture *texture)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y * 32 < data->height)
	{
		while (x * 32 < data->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					texture->walls, x * 32, y * 32);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					texture->floor, x * 32, y * 32);
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_player(t_data *data, t_map *map, t_texture *texture)
{
	mlx_put_image_to_window(data->mlx, data->win, texture->player,
		map->player_x * 32, map->player_y * 32);
}

void	put_collectibles(t_data *data, t_map *map, t_texture *texture)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	map->collectibles_pos = malloc(sizeof(int *) * map->collectibles);
	while (y * 32 < data->height)
	{
		while (x * 32 < data->width)
		{
			if (map->map[y][x] == 'C')
			{
				map->collectibles_pos[i] = malloc(sizeof(int) * 2);
				map->collectibles_pos[i][0] = x * 32;
				map->collectibles_pos[i][1] = y * 32;
				mlx_put_image_to_window(data->mlx, data->win,
					texture->collectible, x * 32, y * 32);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_exit(t_data *data, t_map *map, t_texture *texture)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	map->exits_pos = malloc(sizeof(int *) * map->exits);
	while (y * 32 < data->height)
	{
		while (x * 32 < data->width)
		{
			if (map->map[y][x] == 'E')
			{
				map->exits_pos[i] = malloc(sizeof(int) * 2);
				map->exits_pos[i][0] = x * 32;
				map->exits_pos[i][1] = y * 32;
				mlx_put_image_to_window(data->mlx, data->win,
					texture->exit, x * 32, y * 32);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
