/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:40:23 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/06 20:10:21 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_border(t_vars *vars)
{
	int		i;
	int		fd;
	char	*ptr;

	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->height - 1)
	{
		ptr = gnl(fd);
		if (!ptr)
			return (0);
		if (vars->map[0][i] != '1' || vars->map[vars->height - 1][i] != '1'
			|| vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			close(fd);
			free(ptr);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
			free_double_pointer(vars->map);
			ft_printf("map is not surrounded by walls.\n");
			exit(0);
		}
		i++;
		free(ptr);
	}
	close(fd);
	return (0);
}

void	map_dimensions(t_vars *vars)
{
	vars->width = map_width(vars);
	vars->height = map_height(vars->map_name);
}

void	validate_map(t_vars *vars)
{
	map_dimensions(vars);
	validate_map_name(vars->map_name);
	validate_map_free(vars);
	validate_map_border(vars);
	validate_map_components(vars->map);
	validate_map_rectangular(vars, 0, 0);
	//path_finder(vars->map, vars->counts.count_eggs, 0);
}
