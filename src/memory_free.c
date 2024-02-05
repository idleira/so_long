/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:10 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:44 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
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
	mlx_destroy_image(vars->mlx, vars->img.player_left);
	mlx_destroy_image(vars->mlx, vars->img.player_right);
	mlx_destroy_image(vars->mlx, vars->img.player_front);
	mlx_destroy_image(vars->mlx, vars->img.player_back);
	mlx_destroy_image(vars->mlx, vars->img.wall);
}
