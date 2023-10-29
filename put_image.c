/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:49:22 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 15:45:07 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_image(t_data *image, t_data *block, int image_x, int image_y)
{
	unsigned int	color;

	for (int block_y = 0; block_y < block->img_height; block_y++)
	{
		for (int block_x = 0; block_x < block->img_width; block_x++)
		{
			color = exact_image_color(block, block_x, block_y);
			my_mlx_pixel_put(image, image_x + block_x, image_y + block_y, color);
		}
	}
}

void	put_image_empty(t_data *image, int image_x, int image_y)
{
	for (int block_y = 0; block_y <	50; block_y++)
	{
		for (int block_x = 0; block_x < 50; block_x++)
		{
			my_mlx_pixel_put(image, image_x + block_x, image_y + block_y, 0xFF000000);
		}
	}
}