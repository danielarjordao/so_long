/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:44 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/23 15:28:44 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *file)
{
	char	*ber;
	char	*file_extension;

	ber = ".ber";
	file_extension = file + ft_strlen(file) - ft_strlen(ber);
	return (ft_strncmp(file_extension, ber, ft_strlen(ber)));
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_content(char *line, t_map *map, int n_line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			add_wall(n_line, i, map);
		else if (line[i] == 'P' && map->player_x < 1)
			add_player(n_line, i, map);
		else if (line[i] == 'C')
			add_collectible(n_line, i, map);
		else if (line[i] == 'E' && map->exit < 1)
			add_exit(n_line, i, map);
		else if (line[i] == '0')
			add_floor(n_line, i, map);
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

int	check_reachable(t_data *data)
{
	int		x;
	int		y;
	char	**temp_map;

	y = 0;
	x = 0;
	temp_map = copy_map(data->map->map, data->map->rows);
	if (!temp_map)
		return (1);
	if (check_reachable_aux(data, temp_map, x, y))
		return (1);
	return (0);
}

int	check_reachable_aux(t_data *data, char **temp_map, int x, int y)
{
	while (temp_map[y])
	{
		x = 0;
		while (temp_map[y][x])
		{
			if (temp_map[y][x] == 'E' || temp_map[y][x] == 'C')
			{
				if (!is_acessible(data, temp_map, x, y))
					return (free_array(temp_map), 1);
				free_array(temp_map);
				temp_map = copy_map(data->map->map, data->map->rows);
			}
			x++;
		}
		y++;
	}
	free_array(temp_map);
	return (0);
}
