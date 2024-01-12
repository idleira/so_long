/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:38:32 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 18:58:30 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_name_control(char *map_name, t_vars *vars)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[--len] == 'r')
	{
		if (map_name[--len] == 'e')
		{
			if (map_name[--len] == 'b')
			{
				if (map_name[--len] == '.')
					;
				else
					error_messages(1, vars);
			}
			else
				error_messages(1, vars);
		}
		else
			error_messages(1, vars);
	}
	else
		error_messages(1, vars);
}

void	mapfree_control(t_vars *vars)
{
	int		fd;
	char	*tmp;

	fd = open(vars->map_name, O_RDONLY);
	tmp = gnl(fd);
	if (tmp == NULL)
	{
		free_mapfree(vars);
		exit(ft_printf("\033[0;31merror\nwrong or empty map\n"));
	}
	free(tmp);
}

void	control_components(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P' ||
				map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'V')
				;
			else
				error_messages(2, vars);
			j++;
		}
		i++;
	}
}

void	rectangular(t_vars *vars, int i, int j)
{
	int	area;
	int	count;

	area = (vars->len_height) * (vars->width);
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
			else
				error_messages(2, vars);
			j++;
		}
		i++;
	}
	if (count != area)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31merror\nmap has to be rectangular.\n"));
	}
}
