/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:40:23 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/10 18:18:43 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_border(t_vars *vars)
{
	int		i;

	i = 0;
	while (i < vars->height - 1)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->height - 1][i] != '1'
			|| vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			free_double_pointer(vars->map);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
			ft_printf("map is not surrounded by walls.\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

void	map_dimensions(t_vars *vars)
{
	vars->width = map_width(vars);
	vars->height = map_height(vars->map_name);
}

void	map_validate(t_vars *vars)
{
	validate_map_name(vars);
	map_dimensions(vars);
	validate_map_components(vars);
	validate_map_rectangular(vars, 0, 0);
	validate_map_border(vars);
}
