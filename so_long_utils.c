/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:21:35 by seungule          #+#    #+#             */
/*   Updated: 2023/11/04 19:54:02 by seungule         ###   ########.fr       */
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
}

void	free_map(t_map *map, char **checked_map)
{
	int	i;

	i = 0;
	if (map && map->map_info)
	{
		while (map->map_info[i])
			free(map->map_info[i++]);
		free(map->map_info);
		map->map_info = NULL;
	}
	i = 0;
	if (checked_map)
	{
		while (checked_map[i])
			free(checked_map[i++]);
		free(checked_map);
		checked_map = NULL;
	}
	error();
}

void	free_map_not_error(t_vars *vars, char **checked_map)
{
	int	i;

	i = 0;
	if (vars && vars->map.map_info)
	{
		while (vars->map.map_info[i])
			free(vars->map.map_info[i++]);
		free(vars->map.map_info);
	}
	i = 0;
	if (checked_map)
	{
		while (checked_map[i])
			free(checked_map[i++]);
		free(checked_map);
	}
}
