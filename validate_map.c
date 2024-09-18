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

int	check_map_content(char *line, size_t len, int n_line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strlen(line) != len || line[0] != '1')
			return (1);
		if (line[i] == '1')
			add_wall(n_line, i, map);
		else if (line[i] == 'P' && map->player_x < 1)
			add_player(n_line, i, map);
		else if (line[i] == 'C')
			add_collectible(n_line, i, map);
		else if (line[i] == 'E' && map->exits < 1)
			add_exit(n_line, i, map);
		else if (line[i] == '0')
			add_floor(n_line, i, map);
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	ft_printf("\n");
	return (0);
}

int	check_map(char *file, t_map *map)
{
	char	**line;
	int		i;
	int		fd;

	i = 0;

	if (init_map(file, map, &line, &fd) || check_wall(line[0]))
	{
		handle_error(fd, line, map);
		return (1);
	}
	while (line[i])
	{
		map->map[i] = ft_calloc(ft_strlen(line[0]) + 1, sizeof(char));
		if (!map->map[i]
			|| check_map_content(line[i], ft_strlen(line[0]), i, map))
		{
			handle_error(fd, line, map);
			return (1);
		}
		i++;
		line[i] = get_next_line(fd);
	}
	if (check_wall(line[i - 1]) || map->player_x < 1 || map->exits < 1)
	{
		handle_error(fd, line, map);
		return (1);
	}
	close(fd);
	map->rows = ft_strlen(line[0]) - 1;
	return (0);
}
