/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:16:50 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/14 18:16:50 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->textures = ft_calloc(1, sizeof(t_textures));
	data->map = ft_calloc(1, sizeof(t_map));
}

char	**init_line(char **file, t_map *map)
{
	int		fd;
	int		i;
	char	**line;
	int		n_lines;

	fd = open(*file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	n_lines = count_lines(*file);
	if (n_lines <= 0)
		return (NULL);
	line = ft_calloc(n_lines + 1, sizeof(char *));
	i = 0;
	line[i] = get_next_line(fd);
	while (line[i])
	{
		i++;
		line[i] = get_next_line(fd);
	}
	map->cols = ft_strlen(line[0]) - 1;
	line[i] = NULL;
	close(fd);
	return (line);
}

int	init_map(char *file, t_map *map)
{
	int		n_lines;
	int		i;

	n_lines = count_lines(file);
	map->map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map->map)
		return (1);
	i = 0;
	while (i < n_lines)
	{
		map->map[i] = ft_calloc(map->cols + 1, sizeof(char));
		i++;
	}
	map->map[i] = NULL;
	map->rows = n_lines;
	return (0);
}


void free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
		array = NULL;
	}
}

#include <stdlib.h>

void handle_error(t_data *data)
{
	get_next_line(-1);
	if (!data)
		return;
	if (data->map)
	{
		if (data->map->map)
			free_array(data->map->map);
		free(data->map);
	}
	if (data->textures)
		free(data->textures);
	free(data);
}

void destroy_textures(t_data *data)
{
	if (data->textures->walls)
		mlx_destroy_image(data->mlx, data->textures->walls);
	if (data->textures->floor)
		mlx_destroy_image(data->mlx, data->textures->floor);
	if (data->textures->player)
		mlx_destroy_image(data->mlx, data->textures->player);
	if (data->textures->collectible)
		mlx_destroy_image(data->mlx, data->textures->collectible);
	if (data->textures->exit)
		mlx_destroy_image(data->mlx, data->textures->exit);
}
