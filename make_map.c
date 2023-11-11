/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:19 by seungule          #+#    #+#             */
/*   Updated: 2023/11/11 17:06:24 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_blocks_info3(t_vars *vars)
{
	vars->block.item_block.img = mlx_xpm_file_to_image(vars->mlx,
			vars->block.item_path,
			&vars->block.item_block.img_width,
			&vars->block.item_block.img_height);
	vars->block.item_block.addr = mlx_get_data_addr(vars->block.item_block.img,
			&vars->block.item_block.bits_per_pixel,
			&vars->block.item_block.line_length,
			&vars->block.item_block.endian);
	vars->block.exit_block.img = mlx_xpm_file_to_image(vars->mlx,
			vars->block.exit_path,
			&vars->block.exit_block.img_width,
			&vars->block.exit_block.img_height);
	vars->block.exit_block.addr = mlx_get_data_addr(vars->block.exit_block.img,
			&vars->block.exit_block.bits_per_pixel,
			&vars->block.exit_block.line_length,
			&vars->block.exit_block.endian);
}

void	get_blocks_info2(t_vars *vars)
{
	vars->block.bg_block.img = mlx_xpm_file_to_image(vars->mlx,
			vars->block.bg_path,
			&vars->block.bg_block.img_width,
			&vars->block.bg_block.img_height);
	vars->block.bg_block.addr = mlx_get_data_addr(vars->block.bg_block.img,
			&vars->block.bg_block.bits_per_pixel,
			&vars->block.bg_block.line_length,
			&vars->block.bg_block.endian);
	vars->block.wall_block.img = mlx_xpm_file_to_image(vars->mlx,
			vars->block.wall_path,
			&vars->block.wall_block.img_width,
			&vars->block.wall_block.img_height);
	vars->block.wall_block.addr = mlx_get_data_addr(vars->block.wall_block.img,
			&vars->block.wall_block.bits_per_pixel,
			&vars->block.wall_block.line_length,
			&vars->block.wall_block.endian);
	vars->block.player_block.img = mlx_xpm_file_to_image(vars->mlx,
			vars->block.player_path,
			&vars->block.player_block.img_width,
			&vars->block.player_block.img_height);
	vars->block.player_block.addr = mlx_get_data_addr(
			vars->block.player_block.img,
			&vars->block.player_block.bits_per_pixel,
			&vars->block.player_block.line_length,
			&vars->block.player_block.endian);
}

void	get_blocks_info(t_vars *vars)
{
	vars->block.bg_path = "./images/background.xpm";
	vars->block.wall_path = "./images/block.xpm";
	vars->block.player_path = "./images/player.xpm";
	vars->block.item_path = "./images/item.xpm";
	vars->block.exit_path = "./images/exit.xpm";
}

void	put_image(t_vars *vars, int i, int j)
{
	if (vars->map.map_info[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->block.wall_block.img,
			j * vars->block.wall_block.img_width,
			i * vars->block.wall_block.img_height);
	else if (vars->map.map_info[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->block.player_block.img,
			j * vars->block.player_block.img_width,
			i * vars->block.player_block.img_height);
	else if (vars->map.map_info[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->block.item_block.img,
			j * vars->block.item_block.img_width,
			i * vars->block.item_block.img_height);
	else if (vars->map.map_info[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->block.exit_block.img,
			j * vars->block.exit_block.img_width,
			i * vars->block.exit_block.img_height);
	else if (vars->map.map_info[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->block.bg_block.img,
			j * vars->block.wall_block.img_width,
			i * vars->block.wall_block.img_height);
}

int	make_map(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (vars->map.map_info[i][j])
		{
			put_image(vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
