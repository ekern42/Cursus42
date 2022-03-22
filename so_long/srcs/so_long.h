/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:28:17 by ekern             #+#    #+#             */
/*   Updated: 2022/03/17 15:10:05 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES	*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/big_lib.h"

/*	STRUCT	*/
typedef struct s_data
{
	char	**map;
	char	*file_map;
	void	*wall;
	void	*floor;
	void	*coll;
	void	*player;
	void	*end;
	void	*mlx;
	void	*mlxwin;
	int		mov_y;
	int		mov_x;
	int		map_w;
	int		map_h;
	int		item_nbr;
	int		p_movement;
}			t_data;

/*	SOURCES	*/
void	fc_map_design_error(t_data *info);
void	fc_error(int error);
void	fc_map_init(t_data info);
int		key_register(int keycode, t_data *info);
int		fc_player_placement(t_data *info);
void	fc_file_format(char *file_map);

#endif