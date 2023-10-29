/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:31:06 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 19:13:38 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int	dfs(t_map *map, char **checked_map, int hei, int wid)
 {
	int	result;

	checked_map[hei][wid] = 1;
	//ft_printf("cheked[%d][%d]\n", hei, wid);

	if (map->map_info[hei][wid] == 'E')
		return (1);
	else if (map->map_info[hei][wid] == 'C')
		map->count[Item]--;

	if (!checked_map[hei + 1][wid] && map->map_info[hei + 1][wid] != '1')
		result = dfs(map, checked_map, hei + 1, wid);
	if (!checked_map[hei][wid + 1] && map->map_info[hei][wid + 1] != '1')
		result = dfs(map, checked_map, hei, wid + 1);
	if (!checked_map[hei - 1][wid] && map->map_info[hei - 1][wid] != '1')
		result = dfs(map, checked_map, hei - 1, wid);
	if (!checked_map[hei][wid - 1] && map->map_info[hei][wid - 1] != '1')
		result = dfs(map, checked_map, hei, wid - 1);
	if (result == 1)
		return (1);
	return (0);
}