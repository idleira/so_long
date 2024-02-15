/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:17:20 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/12 17:36:07 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->player_x - 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_y -= IMG_SIZE;
		vars->player_x -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_back, vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->player_x + 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_y += IMG_SIZE;
		vars->player_x += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player_front,
			vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->player_x][vars->player_y + 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_x += IMG_SIZE;
		vars->player_y += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_right, vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->player_x][vars->player_y - 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_x -= IMG_SIZE;
		vars->player_y -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_left, vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	map_print(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			ft_printf("%c", map[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
