/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:31:06 by seungule          #+#    #+#             */
/*   Updated: 2023/11/18 14:19:05 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_map *map, char **checked_map, int hei, int wid)
{
	if (map->map_info[hei][wid] == 'E')
	{
		map->count[EXIT]--;
		checked_map[hei][wid] = 1;
		return (1);
	}
	else if (map->map_info[hei][wid] == 'C')
		map->count[ITEM]--;
	checked_map[hei][wid] = 1;
	if (!checked_map[hei + 1][wid] && map->map_info[hei + 1][wid] != '1')
		dfs(map, checked_map, hei + 1, wid);
	if (!checked_map[hei][wid + 1] && map->map_info[hei][wid + 1] != '1')
		dfs(map, checked_map, hei, wid + 1);
	if (!checked_map[hei - 1][wid] && map->map_info[hei - 1][wid] != '1')
		dfs(map, checked_map, hei - 1, wid);
	if (!checked_map[hei][wid - 1] && map->map_info[hei][wid - 1] != '1')
		dfs(map, checked_map, hei, wid - 1);
	return (1);
}
