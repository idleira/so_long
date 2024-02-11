/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:15:35 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/10 19:41:18 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_background(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.wall, x, y);
			}
			else if (vars->map[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.floor, x, y);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.player_front, x, y);
				vars->player_x = x;
				vars->player_y = y;
			}
			j++;
		}
		i++;
	}
}

void	draw_egg_exit(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.egg, x, y);
			}
			if (vars->map[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.exit, x, y);
			}
			j++;
		}
		i++;
	}
}

void	draw_chimken(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'V')
			{
				if (vars->enemy.direction == 0)
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->img.chimken_r, x, y);
				else if (vars->enemy.direction == 1)
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->img.chimken_l, x, y);
				vars->enemy.chimken_x = x;
				vars->enemy.chimken_y = y;
				vars->enemy.chimken_i = i;
				vars->enemy.chimken_j = j;
			}
			j++;
		}
		i++;
	}
}

void	draw_images(t_vars	*vars)
{
	draw_background(vars, 0, 0);
	draw_player(vars, 0, 0);
	draw_egg_exit(vars, 0, 0);
	draw_chimken(vars, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 24,
		vars->height * 128 - 12,
		0xFFFFFF, "assets by cup nooble [https://cupnooble.itch.io/]");
}
