/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:15 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 16:37:29 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read_path(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->path.path_map = (int **)malloc(sizeof(int *) * (vars->height + 1));
	while (i < vars->height)
	{
		vars->path.path_map[i] = malloc(sizeof(int) * (vars->width + 1));
		j = 0;
		while (j < vars->width)
		{
			if (i == vars->display_x && j == vars->display_y)
				vars->path.path_map[i][j] = 1;
			else
				vars->path.path_map[i][j] = 0;
			j++;
		}
		vars->path.path_map[i][j] = '\0';
		i++;
	}
	vars->path.path_map[i] = NULL;
}
