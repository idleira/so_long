/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:39 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:42 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_up(t_vars *vars)
{
	vars->map[vars->enemy_i][vars->enemy_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->enemy_x,
		vars->enemy_y);
	vars->enemy_x += IMG_SIZE;
	vars->enemy_j += 1;
	if (vars->map[vars->enemy_i][vars->enemy_j] != 'P')
	{
		vars->map[vars->enemy_i][vars->enemy_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
			vars->enemy_x, vars->enemy_y);
	}
	else
		exit(0);
}

void	enemy_down(t_vars *vars)
{
	vars->map[vars->enemy_i][vars->enemy_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->enemy_x,
		vars->enemy_y);
	vars->enemy_x -= IMG_SIZE;
	vars->enemy_j -= 1;
	if (vars->map[vars->enemy_i][vars->enemy_j] != 'P')
	{
		vars->map[vars->enemy_i][vars->enemy_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
			vars->enemy_x, vars->enemy_y);
	}
	else
		exit(0);
}

void	enemy_patrol(t_vars *vars)
{
	if (vars->enemy_i != 0 && vars->enemy_i != 0)
	{
		if (vars->map[vars->enemy_i][vars->enemy_j + 1] != '1')
		{
			while (vars->map[vars->enemy_i][vars->enemy_j + 1] != '1'
				&& vars->map[vars->enemy_i][vars->enemy_j + 1] != 'C'
				&& vars->map[vars->enemy_i][vars->enemy_j + 1] != 'V'
				&& vars->map[vars->enemy_i][vars->enemy_j + 1] != 'E')
			{
				enemy_up(vars);
			}
		}
		else if (vars->map[vars->enemy_i][vars->enemy_j - 1] != '1')
		{
			while (vars->map[vars->enemy_i][vars->enemy_j - 1] != '1'
				&& vars->map[vars->enemy_i][vars->enemy_j - 1] != 'C'
				&& vars->map[vars->enemy_i][vars->enemy_j - 1] != 'V'
				&& vars->map[vars->enemy_i][vars->enemy_j - 1] != 'E')
			{
				enemy_down(vars);
			}
		}
	}
}

int	anim(t_vars *vars)
{
	static int	i;

	vars->enemyspeed++;
	if (vars->enemyspeed >= 6000)
	{
		enemy_patrol(vars);
		vars->enemyspeed = 0;
	}
	i++;
	if (i >= 60)
	{
		sprite_a(vars);
		i = 0;
	}
	return (1);
}
