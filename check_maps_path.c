/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:57:04 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 19:17:22 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_maps_info(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*string;

	i = 0;
	map->map_info = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	while (i < map->map_height + 1)
		map->map_info[i++] = (char *)malloc(sizeof(char) * (map->map_width + 1));
	fd = open("./maps/maps.ber", O_RDONLY);
	i = 0;
	while (1)
	{
		j = 0;
		string = get_next_line(fd);
		if (!string)
			break ;
		while (string[j])
		{
			map->map_info[i][j] = string[j];
			if (string[j] == 'C')
				map->count[Item]++;
			else if (string[j] == 'P')
			{
				map->count[Player]++;
				map->plr_hei = i;
				map->plr_wid = j;
			}
			else if (string[j] == 'E')
				map->count[Exit]++;
			j++;
		}
		map->map_info[i][j] = '\0';
		free(string);
		i++;
	}
	map->map_info[i] = NULL;
}

void	check_maps_path(t_map *map)
{
	char	**checked_map;
	int		i;
	int		item_count;

	get_maps_info(map);
	//print_maps(map);
	if (map->count[Item] <= 0 || map->count[Player] != 1 || map->count[Exit] != 1)
		free_map(map, NULL);
	i = 0;
	checked_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
	while (i < map->map_height)
	{
		checked_map[i] = (char *)ft_calloc(map->map_width + 1, sizeof(char));
		checked_map[i++][map->map_width] = '\0';
	}
	checked_map[map->map_height] = NULL;
	item_count = map->count[Item];
	if (!dfs(map, checked_map, map->plr_hei, map->plr_wid) || map->count[Item] != 0)
		free_map(map, checked_map);
	//ft_printf("OK!");
}
