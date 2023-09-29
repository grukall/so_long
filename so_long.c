/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:48:58 by seungule          #+#    #+#             */
/*   Updated: 2023/09/29 22:23:37 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_vars	vars;
	t_data	image;
	// char	*relative_path = "./mohsen-ameri-KAjtRSdlj6Q-unsplash.jpg";
	//int		color;
	int		img_width = 500;
	int		img_height = 500;
	int		fd;
	char	*buffer;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "Hellow World!");

	//image.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);

	image.img = mlx_new_image(vars.mlx, img_width, img_height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	fd = open("maps.ber", O_RDONLY);
	int j = 0;
	while (1)
	{
		int	i = 0;
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		while (buffer[i])
		{
			if (buffer[i] == '1')
				my_mlx_pixel_put(&image, i, j, 0x00FF0000);
			else if (buffer[i] == '0')
				my_mlx_pixel_put(&image, i, j, 0x00000000);
			else if (buffer[i] == 'C')
				my_mlx_pixel_put(&image, i ,j, 0x0000FF00);
			else if (buffer[i] == 'P')
				my_mlx_pixel_put(&image, i ,j, 0x000000FF);
			else if (buffer[i] == 'E')
				my_mlx_pixel_put(&image, i ,j, 0x0000FFFF);
			i++;
		}
		j++;
	}
	close(fd);

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
