/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:21 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/13 18:18:43 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_vars *vars)
{
	vars->display_y = map_height(vars->map_name);
	if (vars->display_y == -1)
	{
		ft_putstr_fd("error: invalid map.\n", 2);
		exit(EXIT_FAILURE);
	}
	vars->map = ft_calloc(sizeof(char *), (vars->display_y + 1));
	if (!vars->map)
		exit(EXIT_FAILURE);
	map_store(vars);
}

void	map_store(t_vars *vars)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	if (fd == -1)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->map);
		free(vars->mlx);
		ft_putstr_fd("error: no map.\n", 2);
		exit(1);
	}
	while (i < vars->display_y)
	{
		vars->map[i] = gnl(fd);
		if (!vars->map[i])
		{
			ft_putstr_fd("error: empty map file.\n", 2);
			exit(EXIT_FAILURE);
		}
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
	if (vars->map[i] == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free_double_pointer(vars->map);
		free(vars->mlx);
		ft_putstr_fd("error: unable to open map file.\n", 2);
		exit(1);
	}
	while (vars->map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}
