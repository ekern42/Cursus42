/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:21:31 by ekern             #+#    #+#             */
/*   Updated: 2022/03/02 14:05:35 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fc_file_format(char *file_map)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 0;
	while (file_map[a] != '\0')
	{
		if (file_map[a] == '.')
			b = a;
		a++;
	}
	c = 0;
	d = 0;
	while (file_map[++b] != '\0')
	{
		if (file_map[b] == 'b' || file_map[b] == 'e' || file_map[b] == 'r')
			c++;
		else
			d++;
	}
	if (c != 3 || d != 0)
		fc_error(6);
}

static void	fc_map_object_error(t_data *info)
{
	int	player_count;
	int	end_count;
	int	a;
	int	b;

	player_count = 0;
	info->item_nbr = 0;
	end_count = 0;
	a = -1;
	while (++a < info->map_h)
	{
		b = -1;
		while (info->map[a][++b] != '\n')
		{
			if (info->map[a][b] == 'P')
				player_count++;
			else if (info->map[a][b] == 'E')
				end_count++;
			else if (info->map[a][b] == 'C')
				info->item_nbr++;
		}
	}
	if (player_count != 1 || info->item_nbr == 0 || end_count == 0)
		fc_error(3);
}

static void	fc_map_outline_error(t_data info)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (info.map[a][b] != '\n')
	{
		if (info.map[a][b++] != '1')
			fc_error(5);
	}
	while (a < info.map_h)
	{
		if (info.map[a++][b - 1] != '1')
			fc_error(5);
	}
	while (--b >= 0)
	{
		if (info.map[a - 1][b] != '1')
			fc_error(5);
	}
	while (--a >= 0)
	{
		if (info.map[a][b + 1] != '1')
			fc_error(5);
	}
}

void	fc_map_design_error(t_data *info)
{
	fc_map_outline_error(*info);
	fc_map_object_error(info);
}
