/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:48:58 by seungule          #+#    #+#             */
/*   Updated: 2023/09/30 22:22:58 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_data	background;
	t_map	map;

	map.map_height = 0;
	map.map_width = 0;
	check_maps(&map);

	vars.mlx = mlx_init(); //mlx 라이브러리 초기화
	if (!vars.mlx)
		return (1);

	vars.win_width = map.map_width * 100;
	vars.win_height = map.map_height * 100;

	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "so_long");  //윈도우 생성
	make_background(&background, &vars);

	mlx_put_image_to_window(vars.mlx, vars.win, background.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
