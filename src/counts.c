/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:25 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/10 18:50:42 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_all(t_vars *vars)
{
	vars->counts.count_eggs = 0;
	vars->counts.player_count = 0;
	vars->counts.exit_count = 0;
	vars->path.collectibles = 0;
	vars->collected = 0;
	vars->move_count = 0;
	count_elements(vars, 0, 0);
	count_extra(vars);
	return (0);
}

void	count_elements(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'C')
				vars->counts.count_eggs++;
			else if (vars->map[i][j] == 'P')
				vars->counts.player_count++;
			else if (vars->map[i][j] == 'E')
				vars->counts.exit_count++;
			j++;
		}
		i++;
	}
}

void	count_extra(t_vars *vars)
{
	if (vars->counts.player_count != 1)
	{
		free_double_pointer(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_printf("map should include ONE player.\n");
		exit(0);
	}
	else if (vars->counts.exit_count != 1)
	{
		free_double_pointer(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_printf("map should include ONE exit.\n");
		exit(0);
	}
}
