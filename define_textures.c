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

	i = 32;
	data->texture->walls = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&i, &i);
	data->texture->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&i, &i);
	data->texture->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&i, &i);
	data->texture->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm",
			&i, &i);
	data->texture->exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&i, &i);
}
