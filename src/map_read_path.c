/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:45:14 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/12 19:21:34 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read_path(t_vars *vars)
{
	int	i;

	vars->path.map_copy = malloc(sizeof(char *) * (vars->height + 1));
	if (!vars->path.map_copy)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < vars->height)
	{
		vars->path.map_copy[i] = vars->map[i];
		i++;
	}
	vars->path.map_copy[i] = NULL;
}

int	validate_path(t_vars *vars)
{
	map_read_path(vars);
	path_finder(vars->path.map_copy);
	if (path_finder(vars->path.map_copy) == 1)
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
