/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:25 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/27 17:37:13 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counts(t_vars *vars)
{
	vars->path.collectible_egg = 0;
	vars->counts.count_eggs = 0;
	vars->counts.count_player = 0;
	vars->counts.count_exit = 0;
	vars->collected_egg = 0;
	vars->move_count = 0;
	count_eggs(vars, 0, 0);
	count_player(vars, 0, 0);
	count_exit(vars, 0, 0);
	return (0);
}

void	count_eggs(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'C')
				vars->counts.count_eggs++;
			j++;
		}
		i++;
	}
}

void	count_player(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'P')
				vars->counts.count_player++;
			j++;
		}
		i++;
	}
	if (vars->counts.count_player != 1)
	{
		ft_printf("map should include ONE player");
		free_exit(vars);
		exit(0);
	}
}

void	count_exit(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'E')
				vars->counts.count_exit++;
			j++;
		}
		i++;
	}
	if (vars->counts.count_exit != 1)
	{
		ft_printf("map should include ONE exit");
		free_exit(vars);
		exit(0);
	}
}
