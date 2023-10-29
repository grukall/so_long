/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:21:35 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 19:06:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

void	print_maps(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 0;
		if (!map->map_info[i])
			break ;
		while (map->map_info[i][j])
			ft_printf("%c", map->map_info[i][j++]);
		i++;
	}
	ft_printf("\nItem : %d, Player : %d, Exit : %d\n", map->count[Item], map->count[Player], map->count[Exit]);
}

void	free_map(t_map *map, char **checked_map)
{
	int	i;

	i = 0;
	if (map->map_info)
	{
		while (map->map_info[i])
			free(map->map_info[i++]);
		free(map->map_info);
	}
	i = 0;
	if (checked_map)
	{
		while (checked_map[i])
			free(checked_map[i++]);
		free(checked_map);
	}
	error();
}