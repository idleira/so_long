/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:45:14 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 17:11:32 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
