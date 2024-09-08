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

void	color_screen(t_data *data, int color)
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
int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

// Função que trata o pressionamento de teclas
// keycode == 65307 é a tecla ESC
int	key_press(int keycode, void *param)
{
	if (keycode == 65307)
		close_window(param);
	// Tecla W ou up para pintar a tela de azul
	if (keycode == 119 || keycode == 65362)
		color_screen(param, 0x0000FF);
	// Tecla A ou left para pintar a tela de verde
	if (keycode == 97 || keycode == 65361)
		color_screen(param, 0x00FF00);
	// Tecla S ou down para pintar a tela de vermelho
	if (keycode == 115 || keycode == 65364)
		color_screen(param, 0xFF0000);
	// Tecla D ou right para pintar a tela de amarelo
	if (keycode == 100 || keycode == 65363)
		color_screen(param, 0xFFFF00);

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
	// Define qual função será chamada quando fechar a janela for chamado
	mlx_hook(data.win, 17, 0, close_window, &data);
	// Define qual função será chamada quando uma tecla for pressionada
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	// Initializa o loop da janela para que ela seja exibida
	mlx_loop(data.mlx);
	return (0);
}
