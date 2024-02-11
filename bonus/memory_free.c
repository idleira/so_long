/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 19:52:20 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map_copy(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->path.map_copy[i]);
		i++;
	}
	free(vars->path.map_copy);
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

void	free_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.floor);
	mlx_destroy_image(vars->mlx, vars->img.egg);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.exit_o);
	mlx_destroy_image(vars->mlx, vars->img.player_left);
	mlx_destroy_image(vars->mlx, vars->img.player_right);
	mlx_destroy_image(vars->mlx, vars->img.player_front);
	mlx_destroy_image(vars->mlx, vars->img.player_back);
	mlx_destroy_image(vars->mlx, vars->img.chimken_r);
	mlx_destroy_image(vars->mlx, vars->img.chimken_l);
	mlx_destroy_image(vars->mlx, vars->img.wall);
}
