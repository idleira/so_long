/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:29 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/11 19:21:55 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	images_load(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->height * IMG_SIZE;
	vars->img.floor = mlx_xpm_file_to_image(vars->mlx,
			"./images/dirt.xpm", &x, &y);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/grass.xpm", &x, &y);
	vars->img.player_front = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_front.xpm", &x, &y);
	vars->img.player_back = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_back.xpm", &x, &y);
	vars->img.player_left = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_left.xpm", &x, &y);
	vars->img.player_right = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_right.xpm", &x, &y);
	vars->img.egg = mlx_xpm_file_to_image(vars->mlx,
			"./images/egg.xpm", &x, &y);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &x, &y);
	img_control(vars, x, y);
}

void	img_control(t_vars *vars, int x, int y)
{
	vars->img.chimken_r = mlx_xpm_file_to_image(vars->mlx,
			"./images/chimken_R1.xpm", &x, &y);
	vars->img.chimken_l = mlx_xpm_file_to_image(vars->mlx,
			"./images/chimken_L1.xpm", &x, &y);
	vars->img.exit_o = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit_o.xpm", &x, &y);
	if ((vars->img.floor == NULL || vars->img.wall == NULL)
		|| (vars->img.player_front == NULL || vars->img.player_back == NULL)
		|| (vars->img.player_left == NULL || vars->img.player_right == NULL)
		|| (vars->img.egg == NULL || vars->img.exit == NULL
			|| vars->img.chimken_r == NULL || vars->img.chimken_l == NULL))
	{
		ft_printf("\033[0;31merror\ninvalid image!\n");
		free(vars->img.floor);
		free(vars->img.wall);
		free(vars->img.player_front);
		free(vars->img.player_back);
		free(vars->img.player_left);
		free(vars->img.player_right);
		free(vars->img.egg);
		free(vars->img.chimken_r);
		free(vars->img.chimken_l);
		free(vars->img.exit);
		exit(1);
	}
}
