/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:19 by seungule          #+#    #+#             */
/*   Updated: 2023/11/04 20:08:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_blocks_info(t_vars *vars)
{
	vars->block.bg_path = "./images/background.xpm";
	vars->block.wall_path = "./images/block.xpm";
	vars->block.player_path = "./images/player.xpm";
	vars->block.item_path = "./images/item.xpm";
	vars->block.exit_path = "./images/exit.xpm";
	vars->block.bg_block.img_width = 50;
	vars->block.bg_block.img_height = 50;
	vars->block.wall_block.img_width = 50;
	vars->block.wall_block.img_height = 50;
	vars->block.player_block.img_width = 50;
	vars->block.player_block.img_height = 50;
	vars->block.item_block.img_width = 50;
	vars->block.item_block.img_height = 50;
	vars->block.exit_block.img_width = 50;
	vars->block.exit_block.img_height = 50;
	vars->block.bg_block.img = mlx_xpm_file_to_image(vars->mlx, vars->block.bg_path, &vars->block.bg_block.img_width, &vars->block.bg_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	vars->block.bg_block.addr = mlx_get_data_addr(vars->block.bg_block.img, &vars->block.bg_block.bits_per_pixel, &vars->block.bg_block.line_length, &vars->block.bg_block.endian); //이미지 파일 주소 가져오기
	vars->block.wall_block.img = mlx_xpm_file_to_image(vars->mlx, vars->block.wall_path, &vars->block.wall_block.img_width, &vars->block.wall_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	vars->block.wall_block.addr = mlx_get_data_addr(vars->block.wall_block.img, &vars->block.wall_block.bits_per_pixel, &vars->block.wall_block.line_length, &vars->block.wall_block.endian); //이미지 파일 주소 가져오기
	vars->block.player_block.img = mlx_xpm_file_to_image(vars->mlx, vars->block.player_path, &vars->block.player_block.img_width, &vars->block.player_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	vars->block.player_block.addr = mlx_get_data_addr(vars->block.player_block.img, &vars->block.player_block.bits_per_pixel, &vars->block.player_block.line_length, &vars->block.player_block.endian); //이미지 파일 주소 가져오기
	vars->block.item_block.img = mlx_xpm_file_to_image(vars->mlx, vars->block.item_path, &vars->block.item_block.img_width, &vars->block.item_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	vars->block.item_block.addr = mlx_get_data_addr(vars->block.item_block.img, &vars->block.item_block.bits_per_pixel, &vars->block.item_block.line_length, &vars->block.item_block.endian); //이미지 파일 주소 가져오기
	vars->block.exit_block.img = mlx_xpm_file_to_image(vars->mlx, vars->block.exit_path, &vars->block.exit_block.img_width, &vars->block.exit_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	vars->block.exit_block.addr = mlx_get_data_addr(vars->block.exit_block.img, &vars->block.exit_block.bits_per_pixel, &vars->block.exit_block.line_length, &vars->block.exit_block.endian); //이미지 파일 주소 가져오기
}

int	make_map(t_vars *vars)
{
	t_data	image;
	int		i;
	int		j;

	i = 0;
	image.img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height); //배경이 될 이미지 생성(윈도우 크기에 맞춰서)
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); //배경 주소 가져오기
	while (vars->map.map_info[i])
	{
		j = 0;
		while (vars->map.map_info[i][j])
		{
			if (vars->map.map_info[i][j] == '1')
				put_image(&image, &vars->block.wall_block, j * vars->block.wall_block.img_width, i * vars->block.wall_block.img_height); // '1'이면 벽 픽셀 그리기
			else if (vars->map.map_info[i][j] == 'P')
				put_image(&image, &vars->block.player_block, j * vars->block.player_block.img_width, i * vars->block.player_block.img_height); // 'P'이면 player 그리기
			else if (vars->map.map_info[i][j] == 'C')
				put_image(&image, &vars->block.item_block, j * vars->block.item_block.img_width, i * vars->block.item_block.img_height); // 'C'이면 item 그리기
			else if (vars->map.map_info[i][j] == 'E')
				put_image(&image, &vars->block.exit_block, j * vars->block.exit_block.img_width, i * vars->block.exit_block.img_height); // 'E'이면 탈출구 그리기
			else if (vars->map.map_info[i][j] == '0')
				put_image(&image, &vars->block.bg_block, j * vars->block.wall_block.img_width, i * vars->block.wall_block.img_height); // 빈 땅이면 투명블럭 출력
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, image.img, 0, 0);					  //윈도우에 image.img 넣기
	free(image.img);
	free(image.addr);
	image.img = NULL;
	image.addr = NULL;
	return (0);
}
