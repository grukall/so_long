/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:57:04 by seungule          #+#    #+#             */
/*   Updated: 2023/11/18 14:07:07 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapcpy(t_map *map, char ch, int i, int j)
{
	map->map_info[i][j] = ch;
	if (ch == 'C')
		map->count[ITEM]++;
	else if (ch == 'P')
	{
		map->count[PLAYER]++;
		map->plr_hei = i;
		map->plr_wid = j;
	}
	else if (ch == 'E')
		map->count[EXIT]++;
	return (j + 1);
}

void	get_maps_info(t_map *map, char *map_path)
{
	int		fd;
	int		i;
	int		j;
	char	*string;

	i = 0;
	map->map_info = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	while (i < map->map_height + 1)
		map->map_info[i++] = (char *)malloc(sizeof(char)
				* (map->map_width + 1));
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < map->map_height + 1)
	{
		j = 0;
		string = get_next_line(fd);
		if (!string)
			break ;
		while (string[j] && string[j] != '\n')
			j = mapcpy(map, string[j], i, j);
		map->map_info[i][j] = '\0';
		free(string);
		i++;
	}
	close(fd);
}

void	check_maps_path(t_vars *vars, char *map_path)
{
	char	**checked_map;
	t_map	*map;
	int		i;
	int		item_count;

	map = &(vars->map);
	get_maps_info(map, map_path);
	if (map->count[ITEM] <= 0 || map->count[PLAYER] != 1
		|| map->count[EXIT] != 1)
		free_map(map, NULL);
	i = 0;
	checked_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
	while (i < map->map_height)
		checked_map[i++] = (char *)ft_calloc(map->map_width + 1, sizeof(char));
	checked_map[map->map_height] = NULL;
	item_count = map->count[ITEM];
	if (!dfs(map, checked_map, map->plr_hei, map->plr_wid)
		|| map->count[ITEM] != 0 || map->count[EXIT] != 0)
		free_map(map, checked_map);
	free_map_not_error(NULL, checked_map, map->map_height + 1);
	map->count[ITEM] = item_count;
}
