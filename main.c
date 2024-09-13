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
	{
		ft_printf("painting screen blue\n");
		color_screen(param, 0x0000FF);
	}
	// Tecla A ou left para pintar a tela de verde
	if (keycode == 97 || keycode == 65361)
	{
		ft_printf("painting screen green\n");
		color_screen(param, 0x00FF00);
	}
	// Tecla S ou down para pintar a tela de vermelho
	if (keycode == 115 || keycode == 65364)
	{
		ft_printf("painting screen red\n");
		color_screen(param, 0xFF0000);
	}
	// Tecla D ou right para pintar a tela de amarelo
	if (keycode == 100 || keycode == 65363)
	{
		ft_printf("painting screen yellow\n");
		color_screen(param, 0xFFFF00);
	}

	return (0);
}

int	check_extension(char *file)
{
	char	*ber;
	char	*file_extension;

	ber = ".ber";
	file_extension = file + ft_strlen(file) - ft_strlen(ber);
	return (ft_strncmp(file_extension, ber, ft_strlen(ber)));
}


int	check_map_content(char *line, size_t len)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (ft_strlen(line) != len)
			return (1);
		if (line[i] == '1')
			ft_printf("1");
		else if (line[i] == 'P')
			ft_printf("P");
		else if (line[i] == 'E')
			ft_printf("E");
		else if (line[i] == 'C')
			ft_printf("C");
		else if (line[i] == '0')
			ft_printf("0");
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	ft_printf("\n");
	return (0);
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	count_lines(char *file)
{
	int		n_lines;
	char	buffer;
	int		bytes_read;
	int		fd;

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
	close(fd);
	return (n_lines);
}


int	check_map(char *file)
{
	char	**line;
	size_t		len;
	int		i;
	int		fd;
	int		n_lines;

	i = 0;
	n_lines = count_lines(file);
	if (!n_lines)
		return (1);
	line = malloc(sizeof(char *) * (n_lines + 1));
	if (!line)
		return (1);
	fd = open(file, O_RDONLY);
	line[i] = get_next_line(fd);
	len = ft_strlen(line[i]);
	if (check_wall(line[i]))
		return (1);
	while (line[i])
	{
		if (check_map_content(line[i], len))
			return (1);
		i++;
		line[i] = get_next_line(fd);
	}
	if (check_wall(line[i - 1]))
		return (1);
	line[i] = NULL;
	close(fd);
	return (0);
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->collectibles = 0;
	map->exits = 0;
	map->movements = 0;
	map->collectibles_collected = 0;
	map->exits_reached = 0;
	map->collectibles_pos = NULL;
	map->exits_pos = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;

	if (argc != 2 || check_extension(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	map = malloc(sizeof(t_map));
	init_map(map);
	if (check_map(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
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
