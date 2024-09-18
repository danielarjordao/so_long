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

// Função que trata o pressionamento de teclas
// keycode == 65307 é a tecla ESC
int	key_press(int keycode, void *param)
{
	if (keycode == 65307)
		close_window(param);
	// Tecla W ou up para pintar a tela de azul
	if (keycode == 119 || keycode == 65362)
	{
		ft_printf("turn up\n");
	}
	// Tecla A ou left para pintar a tela de verde
	if (keycode == 97 || keycode == 65361)
	{
		ft_printf("turn left\n");
	}
	// Tecla S ou down para pintar a tela de vermelho
	if (keycode == 115 || keycode == 65364)
	{
		ft_printf("turn down\n");
	}
	// Tecla D ou right para pintar a tela de amarelo
	if (keycode == 100 || keycode == 65363)
	{
		ft_printf("turn right\n");
	}

	return (0);
}

// Função que fecha a janela
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

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

void free_map(t_map *map)
{
	if (!map)
		return ;
	if (map)
	{
		free(map);
		map = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;
	t_texture	texture;

	map = ft_calloc(1, sizeof(t_map));
	if (argc != 2 || check_extension(argv[1]) || (check_map(argv[1], map)))
	{
		write(2, "Error\n", 6);
		free_map(map);
		return (1);
	}
	data.height = map->cols * 32;
	data.width = map->rows * 32;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width, data.height, "so_long");
	draw_map(&data, map, &texture);
	mlx_hook(data.win, 17, 0, close_window, &data);
	// Define qual função será chamada quando uma tecla for pressionada
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	// Initializa o loop da janela para que ela seja exibida
	mlx_loop(data.mlx);
	return (0);
}
