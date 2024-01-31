/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:38:32 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 19:17:43 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *message)
{
	ft_printf("\033[0;31merror\n%s\n", message);
	exit(1);
}

void	validate_map_name(char *map_name)
{
	int	len;
	int	i;

	len = ft_strlen(map_name);
	if (len < 5)
	{
		i = ft_strncmp(map_name + len - 4, ".ber", 4);
		if (i != 0)
			error_exit("invalid map file name\n");
	}
}

void	validate_map_free(t_vars *vars)
{
	int		fd;
	char	*tmp;

	fd = open(vars->map_name, O_RDONLY);
	tmp = gnl(fd);
	if (tmp == NULL)
		error_exit("wrong or empty map\n");
	free(tmp);
}

void	validate_map_components(char **map)
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
				map[i][j] == 'C' || map[i][j] == 'E')
					;
			else
				error_exit("invalid map components. \
							only 0, 1, P, C, E allowed\n");
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
	ft_printf("area: %d\n", area);
	count = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == '1' ||
				vars->map[i][j] == 'P' || vars->map[i][j] == 'C'
				|| vars->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != area)
	{
		error_exit("map has to be rectangular.\n");
	}
}
