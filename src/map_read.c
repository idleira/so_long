/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:21 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/29 18:09:00 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_vars *vars)
{
	int	fd;
	int	i;

	vars->y = vertical_len(vars->map_name);
	vars->map = malloc(sizeof(char *) * (vars->y + 1));
	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->y)
	{
		vars->map[i] = gnl(fd);
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
}

int	vertical_len(char *map_name)
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
	return (count);
}

int	horizontal_len(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}
