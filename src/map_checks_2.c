/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:40:23 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 18:57:25 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_control(t_vars *vars)
{
	int		i;
	int		fd;
	char	*ptr;

	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->len_height - 1)
	{
		ptr = gnl(fd);
		if (vars->map[0][i] != '1' || vars->map[vars->len_height
			- 1][i] != '1')
		{
			free(ptr);
			error_center_top_down(vars);
		}
		else if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			free(ptr);
			error_center_left_right(vars);
		}
		i++;
		free(ptr);
	}
	return (0);
}

void	error_center_top_down()
{
	ft_printf("top or bottom edges not surrounded by walls");
	exit(1);
}

void	error_center_left_right()
{
	ft_printf("right or left edges are not surrounded by walls");
	exit(1);
}

void	map_control_dsl(t_vars *vars)
{
	map_name_control(vars->map_name, vars);
	control_components(vars->map, vars);
	rectangular(vars, 0, 0);
	path_finder(vars->i, vars->j, vars);
	if (vars->counts.coin_count == 0
		|| vars->path.collectible_coin != vars->counts.coin_count)
	{
		ft_printf("\033[0;31merror\nimpossible to complete the game\n");
		free_wrong(vars);
		exit(1);
	}
}
