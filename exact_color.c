/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:16:51 by seungule          #+#    #+#             */
/*   Updated: 2023/09/30 19:04:39 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	exact_image_color(t_data *image, int i, int j)
{
	char	*dst;
	dst = image->addr + (j * image->line_length + i * (image->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}