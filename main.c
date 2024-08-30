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

// Função que trata o clique do mouse
// button == 1 é o botão esquerdo do mouse
// x e y são as coordenadas do clique
int	mouse_click(int button, int x, int y, void *param)
{
	t_data	*data;
	int		color_red;
	int		color_green;
	int		pixel_index;

	data = (t_data *)param;
	color_red = 0xFF0000;
	color_green = 0x00FF00;
	if (button == 1)
	{
		pixel_index = (y * data->size) + (x * (data->bpp / 8));
		*(uint32_t *)(data->data + pixel_index) = color_green;
	}
	else if (button == 3)
	{
		pixel_index = (y * data->size) + (x * (data->bpp / 8));
		*(uint32_t *)(data->data + pixel_index) = color_red;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	clear_screen(t_data *data, int color)
{
	int	x;
	int	y;
	int	pixel_index;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pixel_index = (y * data->size) + (x * (data->bpp / 8));
			*(uint32_t *)(data->data + pixel_index) = color;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

// Função que fecha a janela
int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

// Função que trata o pressionamento de teclas
// keycode == 65307 é a tecla ESC
int	key_press(int keycode, void *param, void *mlx, void *win)
{
	if (keycode == 65307)
		close_window(param);
	return (0);
}

int	main(void)
{
	t_data	data;

	// Inicializando a janela
	data.mlx = mlx_init();
	// Criando a janela
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	// Criando a imagem
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	// Obtendo informações da imagem
	//data: Contém o endereço do primeiro byte da imagem.
	//bpp: Contém o número de bits que compõem um pixel.
	//size_line: Contém o número de bytes que compõem uma linha da imagem.
	//endian: Contém o valor 0 ou 1,
	// que indica se a máquina é little-endian ou big-endian.
	data.data = mlx_get_data_addr(data.img, &data.bpp, &data.size, &data.endian);
	// Limpa a tela com a cor preta
	clear_screen(&data, 0x000000);
	mlx_mouse_hook(data.win, mouse_click, &data);
	// Define qual função será chamada quando fechar a janela for chamado
	mlx_hook(data.win, 17, 0, close_window, &data);
	// Define qual função será chamada quando uma tecla for pressionada
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	// Initializa o loop da janela para que ela seja exibida
	mlx_loop(data.mlx);
	return (0);
}
/*
Desenhando uma linha vermelha na diagonal

	// Definindo a cor vermelha
	int	color_red = 0xFF0000;
	// Desenhando em diferentes posições
	int		x;
	int		y;
	int		i;
	int		pixel_index;
	i = 0;
	// Desenhando uma linha vermelha
	while (i < 800)
	{
		x = i;
		y = i;
		pixel_index = (y * size_line) + (x * (bpp / 8));
		*(uint32_t *)(data + pixel_index) = color_red;
		i++;
	}
	// Coloca a imagem na janela
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	*/
