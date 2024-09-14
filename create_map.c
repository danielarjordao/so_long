/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:11:16 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/14 09:11:16 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_wall(int row, int col, t_map *map)
{
	map->map[row][col] = '1';
	ft_printf("%c", map->map[row][col]);
}

void	add_collectible(int row, int col, t_map *map)
{
	map->map[row][col] = 'C';
	map->collectibles++;
	ft_printf("%c", map->map[row][col]);
}

void	add_exit(int row, int col, t_map *map)
{
	map->map[row][col] = 'E';
	map->exits++;
	ft_printf("%c", map->map[row][col]);
}

void	add_player(int row, int col, t_map *map)
{
	map->map[row][col] = 'P';
	map->player_x = col;
	map->player_y = row;
	ft_printf("%c", map->map[row][col]);
}

void	add_floor(int row, int col, t_map *map)
{
	map->map[row][col] = '0';
	ft_printf("%c", map->map[row][col]);
}
