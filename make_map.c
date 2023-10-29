/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:19 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 20:13:16 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_map(t_data *image, t_map *map, t_vars *vars)
{
	int		fd;
	char	*buffer;
	int		i;
	int		j;
	t_data	wall_block;
	t_data	player_block;
	t_data	item_block;
	t_data	exit_block;
	char	*wall_path = "./images/block.xpm";
	char	*player_path = "./images/player.xpm";
	char	*item_path = "./images/item.xpm";
	char	*exit_path = "./images/exit.xpm";

	fd = open("./maps/maps.ber", O_RDONLY);
	(void)map;
	wall_block.img_width = 50;
	wall_block.img_height = 50;
	player_block.img_width = 50;
	player_block.img_height = 50;
	item_block.img_width = 50;
	item_block.img_height = 50;
	exit_block.img_width = 50;
	exit_block.img_height = 50;

	wall_block.img = mlx_xpm_file_to_image(vars->mlx, wall_path, &wall_block.img_width, &wall_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	wall_block.addr = mlx_get_data_addr(wall_block.img, &wall_block.bits_per_pixel, &wall_block.line_length, &wall_block.endian); //이미지 파일 주소 가져오기

	player_block.img = mlx_xpm_file_to_image(vars->mlx, player_path, &player_block.img_width, &player_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	player_block.addr = mlx_get_data_addr(player_block.img, &player_block.bits_per_pixel, &player_block.line_length, &player_block.endian); //이미지 파일 주소 가져오기

	item_block.img = mlx_xpm_file_to_image(vars->mlx, item_path, &item_block.img_width, &item_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	item_block.addr = mlx_get_data_addr(item_block.img, &item_block.bits_per_pixel, &item_block.line_length, &item_block.endian); //이미지 파일 주소 가져오기

	exit_block.img = mlx_xpm_file_to_image(vars->mlx, exit_path, &exit_block.img_width, &exit_block.img_height); //백그라운드 블록 이미지 파일 변환 후 저장
	exit_block.addr = mlx_get_data_addr(exit_block.img, &exit_block.bits_per_pixel, &exit_block.line_length, &exit_block.endian); //이미지 파일 주소 가져오기

	image->img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height); //배경이 될 이미지 생성(윈도우 크기에 맞춰서)
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian); //배경 주소 가져오기

	j = 0;
	while (1)
	{
		i = 0;
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		while (buffer[i])
		{
			if (buffer[i] == '1')
				put_image(image, &wall_block, i * wall_block.img_width, j * wall_block.img_height); // '1'이면 벽 픽셀 그리기
			else if (buffer[i] == 'P')
				put_image(image, &player_block, i * player_block.img_width, j * player_block.img_height); // 'P'이면 player 그리기
			else if (buffer[i] == 'C')
				put_image(image, &item_block, i * item_block.img_width, j * item_block.img_height); // 'C'이면 item 그리기
			else if (buffer[i] == 'E')
				put_image(image, &exit_block, i * exit_block.img_width, j * exit_block.img_height); // 'E'이면 탈출구 그리기
			else if (buffer[i] == '0')
				put_image_empty(image, i * wall_block.img_width, j * wall_block.img_height);        // 빈 땅이면 투명블럭 출력
			i++;
		}
		j++;
	}
	close(fd);
	mlx_put_image_to_window(vars->mlx, vars->win, image->img, 0, 0);					  //윈도우에 image.img 넣기
	return (0);
}
