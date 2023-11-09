/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:57:00 by seungule          #+#    #+#             */
/*   Updated: 2023/11/09 19:48:16 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid(t_vars *vars, int wid, int hei)
{
	if (vars->map.map_info[hei][wid] == '1')
		return (0);
	else if (vars->map.map_info[hei][wid] == 'C')
	{
		vars->map.map_info[hei][wid] = '0';
		vars->map.count[ITEM]--;
	}
	else if (vars->map.map_info[hei][wid] == 'E' && vars->map.count[ITEM] == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (vars->map.map_info[hei][wid] == 'E')
		return (0);
	return (1);
}

void	move_player(t_vars *vars, int wid, int hei)
{
	int	cur_hei;
	int	cur_wid;

	cur_hei = vars->map.plr_hei;
	cur_wid = vars->map.plr_wid;
	vars->map.map_info[cur_hei][cur_wid] = '0';
	vars->map.map_info[cur_hei + hei][cur_wid + wid] = 'P';
	vars->map.plr_wid = cur_wid + wid;
	vars->map.plr_hei = cur_hei + hei;
	vars->move_count++;
	ft_printf("move_count = %d\n", vars->move_count);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == LEFT
		&& check_valid(vars, vars->map.plr_wid - 1, vars->map.plr_hei))
		move_player(vars, -1, 0);
	else if (keycode == UP
		&& check_valid(vars, vars->map.plr_wid, vars->map.plr_hei + 1))
		move_player(vars, 0, 1);
	else if (keycode == RIGHT
		&& check_valid(vars, vars->map.plr_wid + 1, vars->map.plr_hei))
		move_player(vars, 1, 0);
	else if (keycode == DOWN
		&& check_valid(vars, vars->map.plr_wid, vars->map.plr_hei - 1))
		move_player(vars, 0, -1);
	return (0);
}

int	exit_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
