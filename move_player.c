/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:54:00 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/20 15:54:00 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	// `w` or `up arrow`
	if (keycode == 119 || keycode == 65362)
		walk(data, data->map->player_y - 1, data->map->player_x);
	// `a` or `left arrow`
	if (keycode == 97 || keycode == 65361)
		walk(data, data->map->player_y, data->map->player_x - 1);
	if (keycode == 115 || keycode == 65364)
		walk(data, data->map->player_y + 1, data->map->player_x);
	if (keycode == 100 || keycode == 65363)
		walk(data, data->map->player_y, data->map->player_x + 1);
	return (0);
}

void	walk(t_data *data, int next_y, int next_x)
{
	if (data->map->map[next_y][next_x] == '1')
		return ;
	data->map->moves++;
	ft_printf("Moves: %d\n", data->map->moves);
	if (data->map->map[next_y][next_x] == 'C')
	{
		data->map->collectibles_collected++;
		data->map->map[next_y][next_x] = '0';
	}
	if (data->map->map[next_y][next_x] == 'E')
	{
		if (data->map->collectibles_collected == data->map->collectibles)
		{
			ft_printf("You won!\n");
			close_window(data);
		}
	}
	data->map->player_y = next_y;
	data->map->player_x = next_x;
	put_textures(data, data->map);
	put_player(data, data->map, data->textures);
}
