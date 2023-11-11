/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:04 by seungule          #+#    #+#             */
/*   Updated: 2023/11/11 13:25:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./minilibx_opengl/mlx.h"
# include "./get_next_line/get_next_line.h"

# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# define	EXIT			0
# define	PLAYER			1
# define	ITEM			2
# define	ESC				53
# define	RED_X_BUTTON	17
# define	LEFT			123
# define	UP				125
# define	RIGHT			124
# define	DOWN			126

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;


typedef struct s_block
{
	t_data	bg_block;
	t_data	wall_block;
	t_data	player_block;
	t_data	item_block;
	t_data	exit_block;
	char	*bg_path;
	char	*wall_path;
	char	*player_path;
	char	*item_path;
	char	*exit_path;
}t_block;

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		count[3];
	int		plr_hei;
	int		plr_wid;
	char	**map_info;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		move_count;
	t_map	map;
	t_block	block;
}	t_vars;

int				key_hook(int keycode, t_vars *vars);
int				exit_hook(t_vars *vars);

void			check_maps(t_map *map, char *map_path);
void			check_maps_path(t_vars *vars, char *map_path);
void			get_blocks_info(t_vars *vars);
void			get_blocks_info2(t_vars *vars);
void			get_blocks_info3(t_vars *vars);
int				make_map(t_vars *vars);
void			print_maps(t_map *map);
void			free_map(t_map *map, char **checked_map);

int				dfs(t_map *map, char **checked_map, int start_hei, int start_wid);

void			free_map_not_error(t_vars *vars, char **checked_map, int width);
void			error(void);

#endif