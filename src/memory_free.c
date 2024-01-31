/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 20:02:08 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_path_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->path.path_map[i]);
		i++;
	}
	free(vars->path.path_map);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	free_exit(t_vars *vars)
{
	free_path_map(vars);
	free_map(vars);
	mlx_destroy_image(vars->mlx, vars->img.floor);
	mlx_destroy_image(vars->mlx, vars->img.egg);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.player_left);
	mlx_destroy_image(vars->mlx, vars->img.player_right);
	mlx_destroy_image(vars->mlx, vars->img.player_img);
	mlx_destroy_image(vars->mlx, vars->img.player_back);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_window(vars->mlx, vars->win);
}

void	free_wrong(t_vars *vars)
{
	free_map(vars);
	free_path_map(vars);
}
