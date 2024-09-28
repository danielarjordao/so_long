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

#include "so_long.h"

void	load_textures(t_data *data)
{
	int		i;
	int		j;

	data->textures->walls = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &i, &j);
	data->textures->floor = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &i, &j);
	data->textures->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &i, &j);
	data->textures->collectible = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible.xpm", &i, &j);
	data->textures->exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &i, &j);
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			put_image(data, data->map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_image(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->walls, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->collectible, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->floor, x * 32, y * 32);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->player, data->map->player_x * 32,
		data->map->player_y * 32);
}
