/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 17:30:57 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	path_finder(int display_y, int display_x, t_vars *vars)
{
	path_down(display_y, display_x, vars);
	path_up(display_y, display_x, vars);
	path_right(display_y, display_x, vars);
	path_left(display_y, display_x, vars);
	return (1);
}

int	path_down(int display_y, int display_x, t_vars *vars)
{
	if ((vars->map[display_y + 1][display_x] != '1')
		&& vars->path.map_copy[display_y + 1][display_x] < 1)
	{
		if (vars->map[display_y + 1][display_x] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[display_y + 1][display_x]
			= vars->path.map_copy[display_y][display_x] + 1;
		path_finder(display_y + 1, display_x, vars);
	}
	return (1);
}

int	path_up(int display_y, int display_x, t_vars *vars)
{
	if ((vars->map[display_y - 1][display_x] != '1')
		&& vars->path.map_copy[display_y - 1][display_x] < 1)
	{
		if (vars->map[display_y - 1][display_x] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[display_y - 1][display_x]
			= vars->path.map_copy[display_y][display_x] + 1;
		path_finder(display_y - 1, display_x, vars);
	}
	return (1);
}

int	path_right(int display_y, int display_x, t_vars *vars)
{
	if ((vars->map[display_y][display_x + 1] != '1')
		&& vars->path.map_copy[display_y][display_x + 1] < 1)
	{
		if (vars->map[display_y][display_x + 1] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[display_y][display_x + 1]
			= vars->path.map_copy[display_y][display_x] + 1;
		path_finder(display_y, display_x + 1, vars);
	}
	return (1);
}

int	path_left(int display_y, int display_x, t_vars *vars)
{
	if ((vars->map[display_y][display_x - 1] != '1')
		&& vars->path.map_copy[display_y][display_x - 1] < 1)
	{
		if (vars->map[display_y][display_x - 1] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[display_y][display_x - 1]
			= vars->path.map_copy[display_y][display_x] + 1;
		path_finder(display_y, display_x - 1, vars);
	}
	return (1);
}
