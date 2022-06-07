/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:26:18 by ekern             #+#    #+#             */
/*   Updated: 2022/04/05 14:37:15 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fc_letter_sort(t_data info, char *str, int y)
{
	int	x;
	int	a;

	x = 0;
	a = -1;
	while (str[++a] != '\n')
	{
		if (str[a] == '1')
			mlx_put_image_to_window(info.mlx, info.mlxwin, info.wall, x, y);
		else if (str[a] == '0')
			mlx_put_image_to_window(info.mlx, info.mlxwin, info.floor, x, y);
		else if (str[a] == 'P')
			mlx_put_image_to_window(info.mlx, info.mlxwin, info.player, x, y);
		else if (str[a] == 'E')
			mlx_put_image_to_window(info.mlx, info.mlxwin, info.end, x, y);
		else if (str[a] == 'C')
			mlx_put_image_to_window(info.mlx, info.mlxwin, info.coll, x, y);
		else
		{
			mlx_destroy_window(info.mlx, info.mlxwin);
			fc_error(3);
		}
		x += 51;
	}
}

void	fc_map_init(t_data info)
{
	int	a;
	int	y;

	a = -1;
	y = 0;
	while (info.map[++a] != NULL)
	{
		if (info.map[a] == NULL)
			break ;
		fc_letter_sort(info, info.map[a], y);
		y += 51;
	}
}
