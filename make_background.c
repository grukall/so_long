/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:53:48 by seungule          #+#    #+#             */
/*   Updated: 2023/09/30 20:55:49 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_background(t_data *background, t_vars *vars)
{
	t_data	bg_block;
	char	*relative_path = "./images/background.xpm";

	bg_block.img_width = 50;
	bg_block.img_height = 50;
	background->img_width = vars->win_width;
	background->img_height = vars->win_height;

	bg_block.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &bg_block.img_width, &bg_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	bg_block.addr = mlx_get_data_addr(bg_block.img, &bg_block.bits_per_pixel, &bg_block.line_length, &bg_block.endian); //이미지 파일 주소 가져오기

	background->img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height); //배경이 될 이미지 생성(윈도우 크기에 맞춰서)
	background->addr = mlx_get_data_addr(background->img, &background->bits_per_pixel, &background->line_length, &background->endian); //배경 주소 가져오기

	for(int background_y = 0; background_y < background->img_height; ) //백그라운드에 블록 채우기 시작
	{
		for(int background_x = 0; background_x < background->img_width; )
		{
			put_image(background, &bg_block, background_x, background_y);
			background_x += bg_block.img_width;
		}
		background_y += bg_block.img_height;
	}
}
