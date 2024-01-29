/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/29 15:49:01 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imap(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->path.imap[i]);
		i++;
	}
	free(vars->path.imap);
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
	free_imap(vars);
	free_map(vars);
	mlx_destroy_image(vars->mlx, vars->m.floor);
	mlx_destroy_image(vars->mlx, vars->m.egg);
	mlx_destroy_image(vars->mlx, vars->m.exit);
	mlx_destroy_image(vars->mlx, vars->m.player_left);
	mlx_destroy_image(vars->mlx, vars->m.player_right);
	mlx_destroy_image(vars->mlx, vars->m.player_img);
	mlx_destroy_image(vars->mlx, vars->m.player_back);
	mlx_destroy_image(vars->mlx, vars->m.wall);
	mlx_destroy_window(vars->mlx, vars->win);
}

void	free_wrong(t_vars *vars)
{
	free_map(vars);
	free_imap(vars);
}

void	free_mapfree(t_vars *vars)
{
	free(vars->path.imap);
}
