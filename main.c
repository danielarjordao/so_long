/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:03:25 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/30 11:03:25 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	init_data(data);
	if (argc != 2 || check_extension(argv[1]) || (validate_map(argv[1], data)))
	{
		write(1, "\"Error\"\n", 8);
		ft_printf("The map is invalid.\n");
		if (data)
			handle_close(data);
		return (1);
	}
	data->mlx = mlx_init();
	data->height = data->map->rows * 32;
	data->width = data->map->cols * 32;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	load_textures(data);
	draw_map(data);
	play_game(data);
	return (0);
}
