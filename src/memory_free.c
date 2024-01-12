/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 16:39:04 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imap(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_height)
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
	while (i < vars->len_height)
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
	mlx_destroy_image(vars->mlx, vars->m.b);
	mlx_destroy_image(vars->mlx, vars->m.c);
	mlx_destroy_image(vars->mlx, vars->m.e);
	mlx_destroy_image(vars->mlx, vars->m.exit_o_img);
	mlx_destroy_image(vars->mlx, vars->m.player_left_img);
	mlx_destroy_image(vars->mlx, vars->m.player_right_img);
	mlx_destroy_image(vars->mlx, vars->m.player_img);
	mlx_destroy_image(vars->mlx, vars->m.player_back_img);
	mlx_destroy_image(vars->mlx, vars->m.enemy_img);
	mlx_destroy_image(vars->mlx, vars->m.w);
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
