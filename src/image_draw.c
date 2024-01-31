/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:15:35 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 20:01:50 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
					vars->img.player_img, x, y);
				vars->player_x = x;
				vars->player_y = y;
			}
			j++;
		}
		i++;
	}
}

void	draw_egg(t_vars *vars, int i, int j)
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
			j++;
		}
		i++;
	}
}

void	draw_exit(t_vars *vars, int i, int j)
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

void	draw_images(t_vars	*vars)
{
	draw_background(vars, 0, 0);
	draw_player(vars, 0, 0);
	draw_egg(vars, 0, 0);
	draw_exit(vars, 0, 0);
}