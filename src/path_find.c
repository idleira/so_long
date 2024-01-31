/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 20:00:16 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(int y, int x, t_vars *vars)
{
	if ((vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'V')
		&& vars->path.path_map[y + 1][x] < 1)
	{
		if (vars->map[y + 1][x] == 'C')
			vars->path.collectible_egg++;
		vars->path.path_map[y + 1][x] = vars->path.path_map[y][x] + 1;
		path_finder(y + 1, x, vars);
	}
	path_up(y, x, vars);
	path_right(y, x, vars);
	path_left(y, x, vars);
	return (1);
}

int	path_up(int y, int x, t_vars *vars)
{
	if ((vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'V')
		&& vars->path.path_map[y - 1][x] < 1)
	{
		if (vars->map[y - 1][x] == 'C')
			vars->path.collectible_egg++;
		vars->path.path_map[y - 1][x] = vars->path.path_map[y][x] + 1;
		path_finder(y - 1, x, vars);
	}
	return (1);
}

int	path_right(int y, int x, t_vars *vars)
{
	if ((vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'V')
		&& vars->path.path_map[y][x + 1] < 1)
	{
		if (vars->map[y][x + 1] == 'C')
			vars->path.collectible_egg++;
		vars->path.path_map[y][x + 1] = vars->path.path_map[y][x] + 1;
		path_finder(y, x + 1, vars);
	}
	return (1);
}

int	path_left(int y, int x, t_vars *vars)
{
	if ((vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'V')
		&& vars->path.path_map[y][x - 1] < 1)
	{
		if (vars->map[y][x - 1] == 'C')
			vars->path.collectible_egg++;
		vars->path.path_map[y][x - 1] = vars->path.path_map[y][x] + 1;
		path_finder(y, x - 1, vars);
	}
	return (1);
}
