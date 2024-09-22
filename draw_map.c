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

void	draw_map(t_data *data)
{
	put_textures(data, data->map);
	put_player(data, data->map, data->textures);
}

void	put_textures(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < data->map->rows)
	{
		while (x < data->map->cols)
		{
			if (map->map[y][x] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->textures->walls , x * 32, y * 32);
			}
			else if (data->map->map[y][x] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win,
				data->textures->exit, x * 32, y * 32);
				data->map->exit++;
			}
			else if (data->map->map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->textures->collectible, x * 32, y * 32);
			}
			else
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->textures->floor, x * 32, y * 32);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_player(t_data *data, t_map *map, t_textures *textures)
{
	mlx_put_image_to_window(data->mlx, data->win,
		textures->player, map->player_x * 32, map->player_y * 32);
}

void	put_collectibles(t_data *data, t_map *map, t_textures *textures)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map->rows)
	{
		while (x < data->map->cols)
		{
			if (map->map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					textures->collectible, x * 32, y * 32);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
