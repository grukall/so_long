/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:48:58 by seungule          #+#    #+#             */
/*   Updated: 2023/11/04 20:52:39 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks()
{
	system("leaks so_long");
}

int	main(void)
{
	t_vars	vars;

	atexit(leaks);
	vars.map.map_height = 0;
	vars.map.map_width = 0;
	vars.map.count[EXIT] = 0;
	vars.map.count[PLAYER] = 0;
	vars.map.count[ITEM] = 0;
	check_maps(&vars.map);
	check_maps_path(&vars.map);
	vars.mlx = mlx_init();
	vars.win_width = vars.map.map_width * 50;
	vars.win_height = vars.map.map_height * 50;
	get_blocks_info(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "so_long");
	vars.move_count = 0;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, &vars);
	mlx_loop_hook(vars.mlx, make_map, &vars);
	mlx_loop(vars.mlx);
	exit(0);
}
