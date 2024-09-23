/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:32:55 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/23 15:32:55 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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

void handle_close(t_data *data)
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

int	close_window(t_data *data)
{
	destroy_textures(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	handle_close(data);
	exit(0);
}
