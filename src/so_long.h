/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:30 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/18 17:36:39 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/gnl.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define ESC 53
#define W   13
#define A   0
#define S   1
#define D   2

# define IMG_SIZE 128

typedef struct s_counts
{
	int			egg_count;
	int			player_count;
	int			exit_count;
	int			chimken_count;
}				t_counts;

typedef struct	s_path
{
	int			collectible_egg;
	int			spaces;
	int			**imap;
}				t_path;

typedef struct s_images
{
	char		*b;
	char		*w;
	char		*e;
	char		*exit_o_img;
	char		*player_img;
	char		*player_back_img;
	char		*player_left_img;
	char		*player_right_img;
	char		*c;
	char		*chimken_img;
}				t_images;

typedef struct s_vars
{
	t_counts	counts;
	t_path		path;
	t_images	m;
	char		**map;
	char		*map_name;
	void		*mlx;
	void		*win;
	int			width;
	int			len_height;
	int			map_height;
	int			map_width;
	int			move_count;
	int			collected_egg;
	int			chimken_x;
	int			chimken_y;
	int			chimken_i;
	int			chimken_j;
	int			chimkenspeed;
	int			eggspeed;
	char		*mover;
	int			y;
	int			x;
	int			i;
	int			j;
}				t_vars;

void			exit_door(t_vars *vars);
void			map_read(t_vars *vars);
void			put_image(t_vars *vars, int i, int j);
void			upload(t_vars *vars);
void			img_load(t_vars *vars);
void			move_up(t_vars *vars);
void			move_down(t_vars *vars);
void			move_right(t_vars *vars);
void			move_left(t_vars *vars);
void			put_image(t_vars *vars, int i, int j);
void			put_pl(t_vars *vars, int i, int j);
void			put_en(t_vars *vars, int i, int j);
void			put_ce(t_vars *vars, int i, int j);
void			map_control_dsl(t_vars *vars);
void			mapfree_control(t_vars *vars);
void			rectangular(t_vars *vars, int i, int j);
void			control_components(char **map, t_vars *vars);
void			map_name_control(char *map_name, t_vars *vars);
void			error_messages(int i, t_vars *vars);
void			map_read_2(t_vars *vars);
void			player_locate(t_vars *vars);
void			c_egg(t_vars *vars, int i, int j);
void			c_player(t_vars *vars, int i, int j);
void			c_exit(t_vars *vars, int i, int j);
void			free_imap(t_vars *vars);
void			free_map(t_vars *vars);
void			free_exit(t_vars *vars);
void			free_wrong(t_vars *vars);
void			free_mapfree(t_vars *vars);
void			error_center_top_down();
void			error_center_left_right();
void			control(t_vars *vars);

int				path_up(int y, int x, t_vars *vars);
int				path_right(int y, int x, t_vars *vars);
int				path_left(int y, int x, t_vars *vars);

int				vertical_len(char *map_name);
int				horizontal_len(t_vars *vars);
int				map_control(t_vars *vars);
int				player_move(int keycode, t_vars *vars);
int				counts(t_vars *vars);
int				path_finder(int y, int x, t_vars *vars);
int				press_close_key(t_vars *vars);

#endif