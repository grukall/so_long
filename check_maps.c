/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:17 by seungule          #+#    #+#             */
/*   Updated: 2023/11/11 16:56:06 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_string(t_map *map, char *string, int height)
{
	int	i;
	int	len;

	len = ft_strlen(string) - 1;
	i = 0;
	if (string[0] != '1' || string[len - 1] != '1')
		return (0);
	while (i < len)
	{
		if ((height == 1 || height == map->map_height) && string[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_height(t_map *map, char *map_path)
{
	int		fd;
	int		width;
	char	*string;

	fd = open(map_path, O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		width = ft_strlen(string) - 1;
		if (string[width] == '1')
			width++;
		if (map->map_height != 0 && width != map->map_width)
			error();
		map->map_width = width;
		map->map_height++;
		free(string);
	}
	close(fd);
}

void	check_maps(t_map *map, char *map_path)
{
	int		fd;
	int		height;
	char	*string;

	height = 1;
	check_map_height(map, map_path);
	if (map->map_height <= 0)
		error();
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		if (!check_string(map, string, height))
		{
			free(string);
			close(fd);
			error();
		}
		height++;
		free(string);
	}
	close(fd);
}
