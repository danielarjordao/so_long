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

int	count_lines(char *file)
{
	int		n_lines;
	char	buffer;
	int		fd;
	int		bytes_read;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	n_lines = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		if (buffer == '\n')
			n_lines++;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read == 0 && buffer != '\n')
		n_lines++;
	close(fd);
	return (n_lines);
}

char	**copy_map(char **map, int rows)
{
	char	**temp_map;
	int		i;

	temp_map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		temp_map[i] = ft_strdup(map[i]);
		if (!temp_map[i])
		{
			while (i >= 0)
			{
				free(temp_map[i]);
				i--;
			}
			return (NULL);
		}
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}
