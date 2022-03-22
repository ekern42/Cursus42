/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:21:41 by ekern             #+#    #+#             */
/*   Updated: 2022/03/14 13:51:13 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fc_map_mod(t_data *info, int a, int b)
{
	info->map[a][b] = '0';
	ft_printf("Step count: %d\n", ++info->p_movement);
	if (info->map[a + info->mov_y][b + info->mov_x] == 'E')
	{
		free (info->map);
		write(1, "Conglaturation\n   You won!\n", 27);
		exit (0);
	}
	if (info->map[a + info->mov_y][b + info->mov_x] == 'C')
		info->item_nbr--;
	info->map[a + info->mov_y][b + info->mov_x] = 'P';
	return (0);
}

static int	fc_player_mov(t_data *info, int a, int b)
{
	int			x;
	int			y;

	x = 51 * b;
	y = 51 * a;
	mlx_put_image_to_window(info->mlx, info->mlxwin, info->floor, x, y);
	x += info->mov_x * 51;
	y += info->mov_y * 51;
	mlx_put_image_to_window(info->mlx, info->mlxwin, info->player, x, y);
	return (0);
}

static int	fc_movement(t_data *info, int a, int b)
{
	int	c;

	c = 0;
	if (info->map[a + info->mov_y][b + info->mov_x] != '1')
	{
		if (info->map[a + info->mov_y][b + info->mov_x] == 'E' && \
		info->item_nbr == 0)
			c = 1;
		else if (info->map[a + info->mov_y][b + info->mov_x] != 'E')
			c = 1;
		else
			ft_printf("Missing %i treasure(s)\n", info->item_nbr);
		if (c == 1)
		{
			fc_player_mov(info, a, b);
			fc_map_mod(info, a, b);
		}
	}
	return (0);
}

int	fc_player_placement(t_data *info)
{
	int	a[2];
	int	b[2];
	int	c;

	a[0] = -1;
	c = 0;
	while (info->map[++a[0]] != NULL && c == 0)
	{
		b[0] = -1;
		while (info->map[a[0]][++b[0]] != '\n' && c == 0)
		{
			if (info->map[a[0]][b[0]] == 'P')
			{
				a[1] = a[0];
				b[1] = b[0];
				c = 1;
			}
		}
	}
	fc_movement(info, a[1], b[1]);
	return (0);
}
