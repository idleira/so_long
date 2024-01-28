/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:40:23 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/28 18:29:19 by ibeliaie         ###   ########.fr       */
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

void validate_map_rectangular(t_vars *vars)
{
    int area;
    int count;
	int i;
	int j;
	
	area = vars->len_height * vars->width;
	count = 0;
	i = 0;
    while (vars->map[i])
	{
        j = 0;
        while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
            if (vars->map[i][j] == '0' || vars->map[i][j] == '1' || vars->map[i][j] == 'P' ||
				vars->map[i][j] == 'C' || vars->map[i][j] == 'E') 
                count++;
            j++;
        }
        i++;
    }
    if (count != area)
        error_exit("map has to be rectangular.\n");
}

void validate_map_edges(t_vars *vars)
{
	int i;
	
	i = 0;
	while (i < vars->len_height - 1)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->len_height - 1][i] != '1')
            error_exit("top or bottom edge is not surrounded by walls");
        else if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
            error_exit("right or left edge is not surrounded by walls");
        i++;
    }
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
	validate_map_name(vars->map_name);
	validate_map_free(vars);
	validate_map_components(vars->map);
	validate_map_rectangular(vars);
	validate_map_edges(vars);
	path_finder(vars->i, vars->j, vars);
	if (vars->counts.count_eggs == 0
		|| vars->path.collectible_egg != vars->counts.count_eggs)
	{
		ft_printf("\033[0;31merror\nimpossible to complete the game\n");
		free_wrong(vars);
		exit(1);
	}
}
