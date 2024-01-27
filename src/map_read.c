/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:21 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/27 19:21:03 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_vars *vars)
{
	int	fd;
	int	i;

	vars->y = vertical_len(vars->map_name);
	vars->map = (char **)malloc(sizeof(char *) * (vars->y + 1));
	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->y)
	{
		vars->map[i] = gnl(fd);
		if (!(vars->map[i]))
			error_exit("failed to read line.\n");
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
}

int	vertical_len(char *map_name)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_exit("failed to open file.\n");
	line = gnl(fd);
	if (!line)
		error_exit("failed to read line.\n");
	while (line)
	{
		count++;
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (count);
}

int	horizontal_len(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != '\n')
		i++;
	return (i);
}
