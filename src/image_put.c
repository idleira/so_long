/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:15:35 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/15 18:17:08 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, int i, int j)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.w, x, y);
			}
			else if (vars->map[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, x, y);
			}
			j++;
		}
		i++;
	}
	put_pl(vars, 0, 0);
}

void	put_pl(t_vars *vars, int i, int j)
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
					vars->m.player_img, x, y);
				vars->x = x;
				vars->y = y;
			}
			j++;
		}
		i++;
	}
	put_en(vars, 0, 0);
}

void	put_en(t_vars *vars, int i, int j)
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
			if (vars->map[i][j] == 'L')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.chimken_img,
										x, y);
				vars->chimken_x = x;
				vars->chimken_y = y;
				vars->chimken_i = i;
				vars->chimken_j = j;
			}
			j++;
		}
		i++;
	}
	put_ce(vars, 0, 0);
}

void	put_ce(t_vars *vars, int i, int j)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.c, x, y);
			}
			else if (vars->map[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e, x, y);
			}
			j++;
		}
		i++;
	}
}

void	put_egg(t_vars *vars, int i, int j)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.c, x, y);
			}
			j++;
		}
		i++;
	}
}
