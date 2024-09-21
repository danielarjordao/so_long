/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:04:13 by dramos-j          #+#    #+#             */
/*   Updated: 2024/09/18 12:04:13 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_textures(t_data *data)
{
	int		i;
	int		j;

	data->textures->walls = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&i, &j);
	data->textures->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&i, &j);
	data->textures->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&i, &j);
	data->textures->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm",
			&i, &j);
	data->textures->exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&i, &j);
}
