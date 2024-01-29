/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:17:20 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/29 15:49:01 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->i - 1][vars->j] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.floor,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->y -= IMG_SIZE;
		vars->i -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_back, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->i + 1][vars->j] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.floor,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->y += IMG_SIZE;
		vars->i += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.player_img,
			vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->i][vars->j + 1] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.floor,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->x += IMG_SIZE;
		vars->j += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_right, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->i][vars->j - 1] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.floor,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->x -= IMG_SIZE;
		vars->j -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_left, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	exit_door(t_vars *vars)
{
	if (vars->map[vars->i][vars->j] == 'E'
		&& vars->collected == vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
			vars->x, vars->y);
		ft_printf("\nyou win!\n");
		exit(0);
	}
	else if (vars->map[vars->i][vars->j] == 'E'
			&& vars->collected != vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
			vars->x, vars->y);
		ft_printf("\nyou have to get all the eggs before you go");
	}
}
