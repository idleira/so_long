/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:21 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/05 17:33:09 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_read_validate(t_vars *vars)
{
	if (vars->player_y == -1)
	{
		ft_putstr_fd("error: invalid map.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	map_read(t_vars *vars)
{
	int	fd;
	int	i;

	vars->player_y = map_height(vars->map_name);
	map_read_validate(vars);
	vars->map = malloc(sizeof(char *) * (vars->player_y + 1));
	if (!vars->map)
		exit(EXIT_FAILURE);
	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("error: unable to open map file.\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < vars->player_y)
	{
		vars->map[i] = gnl(fd);
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
}

int	map_height(char *map_name)
{
	int		count;
	int		fd;
	char	*ptr;

	fd = open(map_name, O_RDONLY);
	ptr = gnl(fd);
	count = 0;
	while (ptr > 0)
	{
		free(ptr);
		ptr = gnl(fd);
		count++;
	}
	close(fd);
	return (count);
}

int	map_width(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}
