/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:29 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 19:51:49 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_load(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->height * IMG_SIZE;
	vars->m.floor = mlx_xpm_file_to_image(vars->mlx,
			"./images/dirt.xpm", &x, &y);
	vars->m.wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/grass.xpm", &x, &y);
	vars->m.player_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_front.xpm", &x, &y);
	vars->m.player_back = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_back.xpm", &x, &y);
	vars->m.player_left = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_left.xpm", &x, &y);
	vars->m.player_right = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_right.xpm", &x, &y);
	vars->m.egg = mlx_xpm_file_to_image(vars->mlx,
			"./images/egg.xpm", &x, &y);
	vars->m.exit = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &x, &y);
	img_control(vars);
}

void	img_control(t_vars *vars)
{
	if ((vars->m.floor == NULL || vars->m.wall == NULL)
		|| (vars->m.player_img == NULL || vars->m.player_back == NULL)
		|| (vars->m.player_left == NULL || vars->m.player_right == NULL)
		|| (vars->m.egg == NULL || vars->m.exit == NULL))
	{
		ft_printf("\033[0;31merror\ninvalid image!\n");
		free(vars->m.floor);
		free(vars->m.wall);
		free(vars->m.player_img);
		free(vars->m.player_back);
		free(vars->m.player_left);
		free(vars->m.player_right);
		free(vars->m.egg);
		free(vars->m.exit);
		exit(1);
	}
}
