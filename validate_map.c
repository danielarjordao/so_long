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

int	check_extension(char *file)
{
	char	*ber;
	char	*file_extension;

	ber = ".ber";
	file_extension = file + ft_strlen(file) - ft_strlen(ber);
	return (ft_strncmp(file_extension, ber, ft_strlen(ber)));
}

int	count_lines(char *file)
{
	int		n_lines;
	char	buffer;
	int		bytes_read;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	n_lines = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		if (buffer == '\n')
			n_lines++;
		bytes_read = read(fd, &buffer, 1);
	}
	close(fd);
	return (n_lines);
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

int	check_map(char *file, t_data *data)
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
	if (data->map->player_x < 1 || data->map->exit < 1 || data->map->collectibles < 1)
	{
		free_array(line);
		return (1);
	}
	free_array(line);
	return (0);
}
