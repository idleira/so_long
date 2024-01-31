/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:30 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 18:01:12 by ibeliaie         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define IMG_SIZE 128

typedef struct s_counts
{
	int			count_eggs;
	int			player_count;
	int			exit_count;
}				t_counts;

typedef struct	s_path
{
	int			collectible_egg;
	int			**imap;
}				t_path;

typedef struct s_images
{
	char		*floor;
	char		*wall;
	char		*exit;
	char		*player_img;
	char		*player_back;
	char		*player_left;
	char		*player_right;
	char		*egg;
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
	int			height;
	int			move_count;
	int			collected;
	int			y;
	int			x;
	int			i;
	int			j;
}				t_vars;

void			validate_map(t_vars *vars);
void			validate_map_free(t_vars *vars);
void			validate_map_name(char *map_name);
void			validate_map_components(char **map);
void			validate_map_rectangular(t_vars *vars, int i, int j);
int				validate_map_border(t_vars *vars);

void			error_center_top_down();
void			error_center_left_right();
void			error_exit(const char *message);

void			map_read(t_vars *vars);
void			map_read_2(t_vars *vars);

int				map_height(char *map_name);
int				map_width(t_vars *vars);
void			map_dimensions(t_vars *vars);

int				count_all(t_vars *vars);
void			count_elements(t_vars *vars, int i, int j);
void    		count_extra(t_vars *vars);

void			put_wall_floor(t_vars *vars, int i, int j);
void			put_player(t_vars *vars, int i, int j);
void			put_egg(t_vars *vars, int i, int j);
void			put_exit(t_vars *vars, int i, int j);

void			move_up(t_vars *vars);
void			move_down(t_vars *vars);
void			move_left(t_vars *vars);
void			move_right(t_vars *vars);
int				player_move(int keycode, t_vars *vars);
int				exit_esc(t_vars *vars);

void			check_exit_door(t_vars *vars);
void			player_locate(t_vars *vars);

void			free_imap(t_vars *vars);
void			free_map(t_vars *vars);
void			free_exit(t_vars *vars);
void			free_wrong(t_vars *vars);


void			img_load(t_vars *vars);
void			img_control(t_vars *vars);

int				path_up(int y, int x, t_vars *vars);
int				path_right(int y, int x, t_vars *vars);
int				path_left(int y, int x, t_vars *vars);
int				path_finder(int y, int x, t_vars *vars);


#endif