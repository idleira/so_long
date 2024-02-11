/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chimken_behaviour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:53 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/11 20:11:07 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_chimken_direction(t_vars *vars, int x, int y)
{
	if (vars->enemy.direction == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.chimken_r, x, y);
	else if (vars->enemy.direction == 1)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.chimken_l, x, y);
}

void	chimken_right(t_vars *vars)
{
	vars->map[vars->enemy.i][vars->enemy.j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
		vars->enemy.chimken_x, vars->enemy.chimken_y);
	vars->enemy.chimken_x += IMG_SIZE;
	vars->enemy.j += 1;
	if (vars->map[vars->enemy.i][vars->enemy.j] != 'P')
	{
		vars->map[vars->enemy.i][vars->enemy.j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken_r,
			vars->enemy.chimken_x, vars->enemy.chimken_y);
	}
	else
		exit(0);
}

void	chimken_left(t_vars *vars)
{
	vars->map[vars->enemy.i][vars->enemy.j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
		vars->enemy.chimken_x, vars->enemy.chimken_y);
	vars->enemy.chimken_x -= IMG_SIZE;
	vars->enemy.j -= 1;
	if (vars->map[vars->enemy.i][vars->enemy.j] != 'P')
	{
		vars->map[vars->enemy.i][vars->enemy.j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken_l,
			vars->enemy.chimken_x, vars->enemy.chimken_y);
	}
	else
		exit(0);
}

void	chimken_patrol(t_vars *vars)
{
	if (vars->enemy.i != 0 && vars->enemy.j != 0)
	{
		if (vars->enemy.direction)
		{
			if (vars->map[vars->enemy.i][vars->enemy.j + 1] != '1'
				&& vars->map[vars->enemy.i][vars->enemy.j + 1] != 'C'
				&& vars->map[vars->enemy.i][vars->enemy.j + 1] != 'V'
				&& vars->map[vars->enemy.i][vars->enemy.j + 1] != 'E')
				chimken_right(vars);
			else
				vars->enemy.direction = 0;
		}
		else
		{
			if (vars->map[vars->enemy.i][vars->enemy.j - 1] != '1'
				&& vars->map[vars->enemy.i][vars->enemy.j - 1] != 'C'
				&& vars->map[vars->enemy.i][vars->enemy.j - 1] != 'V'
				&& vars->map[vars->enemy.i][vars->enemy.j - 1] != 'E')
				chimken_left(vars);
			else
				vars->enemy.direction = 1;
		}
	}
}
