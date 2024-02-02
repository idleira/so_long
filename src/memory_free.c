/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/02 21:12:47 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_vars *vars)
{
	int	i;
	
	if (!vars)
		return;

	i = 0;
	//while (i < vars->height)
	//{
	//	if (vars->path.path_map[i])
	//		free(vars->path.path_map[i]);
	//	i++;
	//}
	free(vars->path.path_map);
	i = 0;
	while (i < vars->height)
	{
		if (vars->map[i])
			free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	free_pointer(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return ;
}

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free_pointer(str[i++]);
		free(str);
		str = NULL;
	}
	return ;
}

void	free_resources(t_vars *vars)
{
	free_maps(vars);
	mlx_destroy_image(vars->mlx, vars->img.floor);
	mlx_destroy_image(vars->mlx, vars->img.egg);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.player_left);
	mlx_destroy_image(vars->mlx, vars->img.player_right);
	mlx_destroy_image(vars->mlx, vars->img.player_front);
	mlx_destroy_image(vars->mlx, vars->img.player_back);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_window(vars->mlx, vars->win);
	free(mlx);
}
