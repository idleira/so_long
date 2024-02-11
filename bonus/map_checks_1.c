/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:38:32 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/11 20:27:37 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_exit(const char *message)
{
	ft_printf("\033[0;31merror\n%s\n", message);
	exit(0);
}

void	validate_map_name(t_vars *vars)
{
	int	len;
	int	i;

	len = ft_strlen(vars->map_name);
	if (len < 5)
	{
		i = ft_strncmp(vars->map_name + len - 4, ".ber", 4);
		if (i != 0)
		{
			mlx_destroy_display(vars->mlx);
			free(vars->map);
			free(vars->mlx);
			error_exit("invalid map file name\n");
		}
	}
}

void	validate_map_components(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == '1' ||
				vars->map[i][j] == 'P' || vars->map[i][j] == 'C' ||
				vars->map[i][j] == 'E' || vars->map[i][j] == 'V')
					;
			else
			{
				free_double_pointer(vars->map);
				mlx_destroy_display(vars->mlx);
				free(vars->mlx);
				error_exit("invalid map components.\n" \
					"only 0, 1, P, C, E, V allowed.\n");
			}
			j++;
		}
		i++;
	}
}

void	validate_map_rectangular(t_vars *vars, int i, int j)
{
	int	area;
	int	count;

	area = (vars->height) * (vars->width);
	count = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == '1' ||
				vars->map[i][j] == 'P' || vars->map[i][j] == 'C'
				|| vars->map[i][j] == 'E' || vars->map[i][j] == 'V')
				count++;
			j++;
		}
		i++;
	}
	if (count != area)
	{
		free_double_pointer(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		error_exit("map has to be rectangular.\n");
	}
}
