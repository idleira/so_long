/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:17:20 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 20:21:57 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->display_x - 1][vars->display_y] != '1')
	{
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->player_x, vars->player_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			vars->map[vars->display_x][vars->display_y] = '0';
		vars->player_y -= IMG_SIZE;
		vars->display_x -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_back, vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] == '0')
			vars->map[vars->display_x][vars->display_y] = 'P';
		if (vars->map[vars->display_x][vars->display_y] == 'C')
		{
			vars->map[vars->display_x][vars->display_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->display_x + 1][vars->display_y] != '1')
	{
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->player_x, vars->player_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			vars->map[vars->display_x][vars->display_y] = '0';
		vars->player_y += IMG_SIZE;
		vars->display_x += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player_front,
			vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] == '0')
			vars->map[vars->display_x][vars->display_y] = 'P';
		if (vars->map[vars->display_x][vars->display_y] == 'C')
		{
			vars->map[vars->display_x][vars->display_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->display_x][vars->display_y + 1] != '1')
	{
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->player_x, vars->player_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			vars->map[vars->display_x][vars->display_y] = '0';
		vars->player_x += IMG_SIZE;
		vars->display_y += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_right, vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] == '0')
			vars->map[vars->display_x][vars->display_y] = 'P';
		if (vars->map[vars->display_x][vars->display_y] == 'C')
		{
			vars->map[vars->display_x][vars->display_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->display_x][vars->display_y - 1] != '1')
	{
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->player_x, vars->player_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] != 'E')
			vars->map[vars->display_x][vars->display_y] = '0';
		vars->player_x -= IMG_SIZE;
		vars->display_y -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_left, vars->player_x, vars->player_y);
		if (vars->map[vars->display_x][vars->display_y] == '0')
			vars->map[vars->display_x][vars->display_y] = 'P';
		if (vars->map[vars->display_x][vars->display_y] == 'C')
		{
			vars->map[vars->display_x][vars->display_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d", vars->move_count);
	}
}

int	press_esc(t_vars *vars)
{
	ft_printf("\n\033[0;35mgame over!\033[0m\n");
	quit(vars);
	exit(0);
}