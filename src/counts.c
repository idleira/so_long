/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:25 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/15 18:17:08 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counts(t_vars *vars)
{
	vars->path.collectible_egg = 0;
	vars->counts.egg_count = 0;
	vars->counts.player_count = 0;
	vars->counts.exit_count = 0;
	vars->counts.chimken_count = 0;
	vars->path.spaces = 0;
	vars->collected_egg = 0;
	vars->move_count = 0;
	c_egg(vars, 0, 0);
	c_player(vars, 0, 0);
	c_exit(vars, 0, 0);
	return (0);
}

void	c_egg(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'C')
				vars->counts.egg_count++;
			j++;
		}
		i++;
	}
}

void	c_player(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'P')
				vars->counts.player_count++;
			j++;
		}
		i++;
	}
	if (vars->counts.player_count != 1)
	{
		ft_printf("map should include ONE player");
		free_exit(vars);
		exit(0);
	}
}

void	c_exit(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'E')
				vars->counts.exit_count++;
			j++;
		}
		i++;
	}
	if (vars->counts.exit_count != 1)
	{
		ft_printf("map should include ONE exit");
		free_exit(vars);
		exit(0);
	}
}
