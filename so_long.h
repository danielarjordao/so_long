/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:13:52 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/30 19:13:52 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	int		movements;
	int		collectibles_collected;
	int		exits_reached;
	int		**collectibles_pos;
	int		**exits_pos;
}	t_map;


#endif
