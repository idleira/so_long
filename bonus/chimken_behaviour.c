/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chimken_behaviour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:53 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/11 19:20:57 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chimken_right(t_vars *vars)
{
	vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor, vars->enemy.chimken_x,
							vars->enemy.chimken_y);
	vars->enemy.chimken_x += IMG_SIZE;
	vars->enemy.chimken_j += 1;
	if (vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] != 'P')
	{
		vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken_r,
								vars->enemy.chimken_x, vars->enemy.chimken_y);
	}
	else
		exit(0);
}

void	chimken_left(t_vars *vars)
{
	vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor, vars->enemy.chimken_x,
							vars->enemy.chimken_y);
	vars->enemy.chimken_x -= IMG_SIZE;
	vars->enemy.chimken_j -= 1;
	if (vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] != 'P')
	{
		vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken_l,
								vars->enemy.chimken_x, vars->enemy.chimken_y);
	}
	else
		exit(0);
}

void	chimken_patrol(t_vars *vars)
{
	if (vars->enemy.chimken_i != 0 && vars->enemy.chimken_j != 0)
	{
		if (vars->enemy.direction)
		{
			if (vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j + 1] != '1'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j + 1] != 'C'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j + 1] != 'V'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j + 1] != 'E')
				chimken_right(vars);
			else
				vars->enemy.direction = 0;
		}
		else
		{
			if (vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j - 1] != '1'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j - 1] != 'C'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j - 1] != 'V'
				&& vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j - 1] != 'E') {
				chimken_left(vars);
			}
			else
				vars->enemy.direction = 1;
		}
	}
}
