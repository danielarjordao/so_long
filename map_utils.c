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

int	init_map(char *file, t_map *map, char ***line, int *n_lines, int *fd, int *len)
{
	*n_lines = count_lines(file);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (1);
	map->map = ft_calloc(*n_lines + 1, sizeof(char *));
	*line = ft_calloc(*n_lines + 1, sizeof(char *));
	(*line)[0] = get_next_line(*fd);
	if (!*line || !map->map)
	{
		handle_error(*fd, *line, map);
		return (1);
	}
	*len = ft_strlen(*line[0]);
	return (0);
}

void	handle_error(int fd, char **line, t_map *map)
{
	close(fd);
	get_next_line(-1);
	if (map->map)
	{
		free_array(map->map);
		map->map = NULL;
	}
	free_array(line);
}
