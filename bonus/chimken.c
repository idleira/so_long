/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chimken.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:53 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 19:52:20 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chimken_up(t_vars *vars)
{
	vars->map[vars->chimken_i][vars->chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
		vars->chimken_x, vars->chimken_y);
	vars->chimken_x += IMG_SIZE;
	vars->chimken_j += 1;
	if (vars->map[vars->chimken_i][vars->chimken_j] != 'P')
	{
		vars->map[vars->chimken_i][vars->chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken,
			vars->chimken_x, vars->chimken_y);
	}
	else
		exit(0);
}

void	chimken_down(t_vars *vars)
{
	vars->map[vars->chimken_i][vars->chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
		vars->chimken_x, vars->chimken_y);
	vars->chimken_x -= IMG_SIZE;
	vars->chimken_j -= 1;
	if (vars->map[vars->chimken_i][vars->chimken_j] != 'P')
	{
		vars->map[vars->chimken_i][vars->chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken,
			vars->chimken_x, vars->chimken_y);
	}
	else
		exit(0);
}

void	chimken_patrol(t_vars *vars)
{
	if (vars->chimken_i != 0 && vars->chimken_j != 0)
	{
		if (vars->map[vars->chimken_i][vars->chimken_j + 1] != '1')
		{
			while (vars->map[vars->chimken_i][vars->chimken_j + 1] != '1'
					&& vars->map[vars->chimken_i][vars->chimken_j + 1] != 'C'
					&& vars->map[vars->chimken_i][vars->chimken_j + 1] != 'V'
					&& vars->map[vars->chimken_i][vars->chimken_j + 1] != 'E')
			{
				chimken_up(vars);
			}
		}
		else if (vars->map[vars->chimken_i][vars->chimken_j - 1] != '1')
		{
			while (vars->map[vars->chimken_i][vars->chimken_j - 1] != '1'
					&& vars->map[vars->chimken_i][vars->chimken_j - 1] != 'C'
					&& vars->map[vars->chimken_i][vars->chimken_j - 1] != 'V'
					&& vars->map[vars->chimken_i][vars->chimken_j - 1] != 'E')
			{
				chimken_down(vars);
			}
		}
	}
}
