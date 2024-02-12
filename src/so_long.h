/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:30 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/10 17:35:15 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"
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

typedef struct s_images
{
	char		*floor;
	char		*wall;
	char		*exit;
	char		*exit_o;
	char		*player_front;
	char		*player_back;
	char		*player_left;
	char		*player_right;
	char		*egg;
}				t_images;

typedef struct s_path
{
	int			collectibles;
	int			**map_copy;
}				t_path;

typedef struct s_vars
{
	t_counts	counts;
	t_images	img;
	t_path		path;
	char		**map;
	char		*map_name;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			move_count;
	int			collected;
	int			player_x;
	int			player_y;
	int			display_x;
	int			display_y;
}				t_vars;

void			validate_map(t_vars *vars);
void			validate_map_name(t_vars *vars);
void			validate_map_components(t_vars *vars);
void			validate_map_rectangular(t_vars *vars, int i, int j);
int				validate_map_border(t_vars *vars);

void			error_exit(const char *message);

void			map_read(t_vars *vars);
void			map_print(int **map);
void			map_store(t_vars *vars);
void			map_read_path(t_vars *vars);

int				map_height(char *map_name);
int				map_width(t_vars *vars);
void			map_dimensions(t_vars *vars);

int				count_all(t_vars *vars);
void			count_elements(t_vars *vars, int i, int j);
void			count_extra(t_vars *vars);

void			draw_background(t_vars *vars, int i, int j);
void			draw_player(t_vars *vars, int i, int j);
void			draw_exit(t_vars *vars, int i, int j);
void			draw_egg(t_vars *vars, int i, int j);
void			draw_images(t_vars	*vars);

void			move_up(t_vars *vars);
void			move_down(t_vars *vars);
void			move_left(t_vars *vars);
void			move_right(t_vars *vars);
int				player_move(int keycode, t_vars *vars);
int				press_esc(t_vars *vars);

void			check_exit(t_vars *vars);
void			player_locate(t_vars *vars);

void			free_map_copy(t_vars *vars);
void			free_pointer(char *str);
void			free_double_pointer(char **str);
void			free_images(t_vars *vars);

void			img_load(t_vars *vars);
void			img_control(t_vars *vars, int x, int y);

int				path_finder(int player_y, int player_x, t_vars *vars);
int				path_up(int player_y, int player_x, t_vars *vars);
int				path_down(int player_y, int player_x, t_vars *vars);
int				path_left(int player_y, int player_x, t_vars *vars);
int				path_right(int player_y, int player_x, t_vars *vars);
int				validate_path(t_vars *vars);

void			quit(t_vars *vars);

#endif