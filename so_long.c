/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:48:58 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 21:05:15 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_data	background;
	t_map	map;
	t_data	image;

	map.map_height = 0;
	map.map_width = 0;
	map.count[Exit] = 0;
	map.count[Player] = 0;
	map.count[Item] = 0;
	check_maps(&map);      //맵의 높이 너비 측정, 벽이 1로 둘러쌓여 있는 지 검사.
	check_maps_path(&map); //맵의 경로가 유효한지, 플레이어 전리품 출구가 하나씩 있는지 검사.
	vars.mlx = mlx_init(); //mlx 라이브러리 초기화
	if (!vars.mlx)
		return (1);

	vars.win_width = map.map_width * 50;   //map의 한 block당 50픽셀 부여
	vars.win_height = map.map_height * 50;
	//ft_printf("vars.win_width : %d, vars.win_height : %d\n", vars.win_width, vars.win_height);

	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "so_long");  //윈도우 생성
	make_background(&background, &vars);                                              //background 이미지 생성
	make_map(&image, &map, &vars);												      //map 이미지 생성
	while (1)
	{
		mlx_key_hook(vars.win, key_hook, &vars); //key hook 규칙 적용
		mlx_hook(vars.win, 17, 0, exit_hook, 0); //17번(종료 버튼)을 누르면 프로세스 종료
		mlx_loop(vars.mlx);                      //키보드랑 마우스 입력을 무한히 기다린다.
		mlx_loop_hook(vars.mlx, make_map, &vars); // hooks 이용해서 정리해야 함	}
	return (0);
}
