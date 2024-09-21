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

// Função que fecha a janela
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	handle_error(data);
	exit(0);
}

void	play_game(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	init_data(data);
	if (argc != 2 || check_extension(argv[1]) || (check_map(argv[1], data)))
	{
		write(2, "Error\n", 6);
		if (data)
			handle_error(data);
		return (1);
	}
	data->mlx = mlx_init();
	data->height = data->map->rows * 32;
	data->width = data->map->cols * 32;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	draw_map(data);
	play_game(data);
	return (0);
}
