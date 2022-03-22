/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:27:26 by ekern             #+#    #+#             */
/*   Updated: 2022/03/17 15:12:31 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fc_error(int error)
{
	ft_printf("Error\n");
	if (error == 2)
		write(1, "Wrong fd\n", 9);
	else if (error == 3)
		write(1, "Map design\n", 11);
	else if (error == 4)
		write(1, "Number of arg should be 2\n", 26);
	else if (error == 5)
		write(1, "Map not closed by wall\n", 23);
	else if (error == 6)
		write(1, "Map file format must finish with .ber\n", 38);
	exit (0);
}

static int	destroy_window(void)
{
	exit (0);
}

static void	fc_initialisation(t_data *info)
{
	char	*path[5];
	int		width;
	int		height;

	path[0] = "./img/collectible.xpm";
	path[1] = "./img/wall.xpm";
	path[2] = "./img/player.xpm";
	path[3] = "./img/end.xpm";
	path[4] = "./img/floor.xpm";
	info->coll = mlx_xpm_file_to_image(info->mlx, path[0], &width, &height);
	info->wall = mlx_xpm_file_to_image(info->mlx, path[1], &width, &height);
	info->player = mlx_xpm_file_to_image(info->mlx, path[2], &width, &height);
	info->end = mlx_xpm_file_to_image(info->mlx, path[3], &width, &height);
	info->floor = mlx_xpm_file_to_image(info->mlx, path[4], &width, &height);
	info->p_movement = 0;
}

static void	fc_map_parsing(t_data *info, char	*file_map)
{
	int		fd;
	int		a;
	int		n;

	a = -1;
	n = 64;
	info->map = malloc(sizeof(char **) * n);
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		fc_error(2);
	while (n-- > 0)
	{
		info->map[++a] = get_next_line(fd);
		if (info->map[a] == NULL)
			break ;
	}
	info->map_h = a;
	a = 0;
	while (info->map[0][a] != '\n')
		a++;
	info->map_w = a;
	close (fd);
}

int	main(int ac, char **av)
{
	t_data	info;

	if (ac != 2)
		fc_error(4);
	fc_file_format(av[1]);
	info.mlx = mlx_init();
	fc_initialisation(&info);
	fc_map_parsing(&info, av[1]);
	fc_map_design_error(&info);
	info.mlxwin = mlx_new_window(info.mlx, info.map_w * 51, info.map_h * 51, \
	"So_long");
	fc_map_init(info);
	mlx_key_hook(info.mlxwin, key_register, &info);
	mlx_hook(info.mlxwin, 17, 1L << 17, destroy_window, &info);
	mlx_loop (info.mlx);
	return (0);
}
