/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chimken_behaviour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:53 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/10 19:53:23 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_position(t_vars *vars, int new_i, int new_j, int move_x)
{
	if (vars->map[new_i][new_j] == '1' || vars->map[new_i][new_j] == 'C' ||
		vars->map[new_i][new_j] == 'V' || vars->map[new_i][new_j] == 'E')
	{
		if (vars->map[new_i][new_j] == 'E')
			exit(0);
		return;
	}
	vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
							vars->enemy.chimken_x, vars->enemy.chimken_y);
	vars->enemy.chimken_i = new_i;
	vars->enemy.chimken_j = new_j;
	vars->enemy.chimken_y += move_x;
	vars->map[vars->enemy.chimken_i][vars->enemy.chimken_j] = 'V';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.chimken,
							vars->enemy.chimken_x, vars->enemy.chimken_y);
}

void	chimken_left(t_vars *vars)
{
	int new_i = vars->enemy.chimken_i;
	int new_j = vars->enemy.chimken_j + 1;

	if (new_i >= 0)
		update_position(vars, new_i, new_j, -IMG_SIZE);
}

void	chimken_right(t_vars *vars)
{
	int new_i = vars->enemy.chimken_i;
	int new_j = vars->enemy.chimken_j + 1;

	if (new_i < vars->height)
		update_position(vars, new_i, new_j, IMG_SIZE);
}

int direction(t_vars *vars)
{
	int	move_direction;

	if (vars->map[vars->enemy.chimken_i + 1][vars->enemy.chimken_j] != '1' &&
		vars->map[vars->enemy.chimken_i + 1][vars->enemy.chimken_j] != 'C' &&
		vars->map[vars->enemy.chimken_i + 1][vars->enemy.chimken_j] != 'V' &&
		vars->map[vars->enemy.chimken_i + 1][vars->enemy.chimken_j] != 'E')
			move_direction = 1;
	else if (vars->map[vars->enemy.chimken_i - 1][vars->enemy.chimken_j] != '1' &&
			vars->map[vars->enemy.chimken_i - 1][vars->enemy.chimken_j] != 'C' &&
			vars->map[vars->enemy.chimken_i - 1][vars->enemy.chimken_j] != 'V' &&
			vars->map[vars->enemy.chimken_i - 1][vars->enemy.chimken_j] != 'E')
			move_direction = -1;
	else
		return (-1);
	return (move_direction);
}

void	chimken_patrol(t_vars *vars)
{
	int move_direction;

	move_direction = direction(vars);
	if (move_direction == 1)
		chimken_right(vars);
	else if (move_direction == -1)
		chimken_left(vars);
}
