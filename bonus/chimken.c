/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chimken.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:39 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:42 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chimken_up(t_vars *vars)
{
	vars->map[vars->chimken_i][vars->chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->chimken_x,
		vars->chimken_y);
	vars->chimken_x += IMG_SIZE;
	vars->chimken_j += 1;
	if (vars->map[vars->chimken_i][vars->chimken_j] != 'P')
	{
		vars->map[vars->chimken_i][vars->chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.chimken_img,
			vars->chimken_x, vars->chimken_y);
	}
	else
		exit(0);
}

void	chimken_down(t_vars *vars)
{
	vars->map[vars->chimken_i][vars->chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->chimken_x,
		vars->chimken_y);
	vars->chimken_x -= IMG_SIZE;
	vars->chimken_j -= 1;
	if (vars->map[vars->chimken_i][vars->chimken_j] != 'P')
	{
		vars->map[vars->chimken_i][vars->chimken_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.chimken_img,
			vars->chimken_x, vars->chimken_y);
	}
	else
		exit(0);
}

void	chimken_patrol(t_vars *vars)
{
	if (vars->chimken_i != 0 && vars->chimken_i != 0)
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

int	anim(t_vars *vars)
{
	static int	i;

	vars->chimkenspeed++;
	if (vars->chimkenspeed >= 6000)
	{
		chimken_patrol(vars);
		vars->chimkenspeed = 0;
	}
	i++;
	if (i >= 60)
	{
		sprite_a(vars);
		i = 0;
	}
	return (1);
}
