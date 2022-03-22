/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:21 by ekern             #+#    #+#             */
/*   Updated: 2022/02/22 15:08:38 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_register(int keycode, t_data *info)
{
	int	result;

	info->mov_y = 0;
	info->mov_x = 0;
	result = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->mlxwin);
		exit (0);
	}
	else if (keycode == 13)
		info->mov_y = -1;
	else if (keycode == 1)
		info->mov_y = 1;
	else if (keycode == 0)
		info->mov_x = -1;
	else if (keycode == 2)
		info->mov_x = 1;
	if (info->mov_x != 0 || info->mov_y != 0)
		fc_player_placement(info);
	return (0);
}
