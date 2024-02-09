/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:45:14 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 17:49:00 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_read_path(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->path.map_copy = (int **)malloc(sizeof(int *) * (vars->height + 1));
	while (i < vars->height)
	{
		vars->path.map_copy[i] = malloc(sizeof(int) * (vars->width + 1));
		j = 0;
		while (j < vars->width)
		{
			if (i == vars->display_x && j == vars->display_y)
				vars->path.map_copy[i][j] = 1;
			else
				vars->path.map_copy[i][j] = 0;
			j++;
		}
		vars->path.map_copy[i][j] = '\0';
		i++;
	}
	vars->path.map_copy[i] = NULL;
}

int validate_path(t_vars *vars)
{
	map_read_path(vars);
	path_finder(vars->display_y, vars->display_x, vars);
	if (vars->counts.count_eggs == 0
		|| vars->path.collectibles != vars->counts.count_eggs)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free_double_pointer(vars->map);
		free_map_copy(vars);
		ft_printf("impossible to complete the game.\n");
		exit(0);
	}
    return (0);
}
