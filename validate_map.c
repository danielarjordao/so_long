/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:15:37 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/13 17:15:37 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char *file, t_data *data)
{
	char	**line;
	int		i;

	line = init_line(&file, data->map);
	if (!line || init_map(file, data->map)
		|| check_wall(line[0]) || check_wall(line[data->map->rows - 1]))
	{
		free_array(line);
		return (1);
	}
	i = 0;
	while (line[i])
	{
		if (check_map_content(line[i], data->map, i))
		{
			free_array(line);
			return (1);
		}
		i++;
	}
	if (data->map->player_x < 1 || data->map->exit < 1
		|| data->map->collectibles < 1 || check_reachable(data))
	{
		free_array(line);
		return (1);
	}
	free_array(line);
	return (0);
}
