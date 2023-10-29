/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:04 by seungule          #+#    #+#             */
/*   Updated: 2023/10/29 19:56:47 by seungule         ###   ########.fr       */
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

# define	Exit	0
# define	Player	1
# define	Item	2

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
}	t_vars;

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		count[3];
	int		plr_hei;
	int		plr_wid;
	char	**map_info;
}	t_map;

int				exit_hook(void);
int				key_hook(int keycode, t_vars *vars);

unsigned int	exact_image_color(t_data *image, int i, int j);
void			make_background(t_data *background, t_vars *vars);
void			put_image(t_data *image, t_data *block, int image_x, int image_y);
void			put_image_empty(t_data *image, int image_x, int image_y);

void			check_maps(t_map *map);
void			check_maps_path(t_map *map);
int				make_map(t_data *image, t_map *map, t_vars *vars);
void			print_maps(t_map *map);
void			free_map(t_map *map, char **checked_map);

int				dfs(t_map *map, char **checked_map, int start_hei, int start_wid);

void			error(void);

#endif