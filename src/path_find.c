/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 17:12:50 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(int player_y, int player_x, t_vars *vars)
{
	if ((vars->map[player_y + 1][player_x] != '1')
		&& vars->path.map_copy[player_y + 1][player_x] < 1)
	{
		if (vars->map[player_y + 1][player_x] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[player_y + 1][player_x] = vars->path.map_copy[player_y][player_x] + 1;
		path_finder(player_y + 1, player_x, vars);
	}
	path_up(player_y, player_x, vars);
	path_right(player_y, player_x, vars);
	path_left(player_y, player_x, vars);
	return (1);
}

int	path_up(int player_y, int player_x, t_vars *vars)
{
	if ((vars->map[player_y - 1][player_x] != '1')
		&& vars->path.map_copy[player_y - 1][player_x] < 1)
	{
		if (vars->map[player_y - 1][player_x] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[player_y - 1][player_x] = vars->path.map_copy[player_y][player_x] + 1;
		path_finder(player_y - 1, player_x, vars);
	}
	return (1);
}

int	path_right(int player_y, int player_x, t_vars *vars)
{
	if ((vars->map[player_y][player_x + 1] != '1')
		&& vars->path.map_copy[player_y][player_x + 1] < 1)
	{
		if (vars->map[player_y][player_x + 1] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[player_y][player_x + 1] = vars->path.map_copy[player_y][player_x] + 1;
		path_finder(player_y, player_x + 1, vars);
	}
	return (1);
}

int	path_left(int player_y, int player_x, t_vars *vars)
{
	if ((vars->map[player_y][player_x - 1] != '1')
		&& vars->path.map_copy[player_y][player_x - 1] < 1)
	{
		if (vars->map[player_y][player_x - 1] == 'C')
			vars->path.collectibles++;
		vars->path.map_copy[player_y][player_x - 1] = vars->path.map_copy[player_y][player_x] + 1;
		path_finder(player_y, player_x - 1, vars);
	}
	return (1);
}
