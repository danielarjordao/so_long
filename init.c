/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:32:14 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/23 15:32:14 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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
		if (ft_strlen(line[0]) != ft_strlen(line[i]))
		{
			free_array(line);
			return (NULL);
		}
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
