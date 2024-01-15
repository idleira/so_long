/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:29 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/15 18:19:56 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_load(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->len_height * IMG_SIZE;
	vars->m.b = mlx_xpm_file_to_image(vars->mlx, "./images/dirt.xpm",
			&x, &y);
	vars->m.w = mlx_xpm_file_to_image(vars->mlx,
			"./images/grass.xpm", &x, &y);
	vars->m.player_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_front.xpm", &x, &y);
	vars->m.player_back_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_back.xpm", &x, &y);
	vars->m.player_left_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_left.xpm", &x, &y);
	vars->m.player_right_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/char_right.xpm", &x, &y);
	vars->m.c = mlx_xpm_file_to_image(vars->mlx,
			"./images/egg.xpm", &x, &y);
	vars->m.e = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &x, &y);
	vars->m.exit_o_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit_o.xpm", &x, &y);
	vars->m.chimken_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/chimken.xpm", &x, &y);
}

void	upload(t_vars *vars)
{
	vars->width = horizontal_len(vars);
	vars->len_height = vertical_len(vars->map_name);
}

void	control(t_vars *vars)
{
	if ((vars->m.b == NULL || vars->m.w == NULL) || (vars->m.player_img == NULL
			|| vars->m.player_back_img == NULL)
		|| (vars->m.player_left_img == NULL || vars->m.player_right_img == NULL)
		|| (vars->m.c == NULL || vars->m.e == NULL)
		|| (vars->m.exit_o_img == NULL || vars->m.chimken_img == NULL))
	{
		ft_printf("\033[0;31merror\ninvalid image!\n");
		free(vars->m.b);
		free(vars->m.w);
		free(vars->m.player_img);
		free(vars->m.player_back_img);
		free(vars->m.player_left_img);
		free(vars->m.player_right_img);
		free(vars->m.e);
		free(vars->m.exit_o_img);
		free(vars->m.chimken_img);
		exit(1);
	}
}

void	bonus_control(t_vars *vars)
{
	if ((vars->s.cs[0] == NULL || vars->s.cs[1] == NULL)
		|| (vars->s.cs[2] == NULL || vars->s.cs[3] == NULL))
	{
		ft_printf("\033[0;31merror\ninvalid image!\n");
		free(vars->s.cs[0]);
		free(vars->s.cs[1]);
		free(vars->s.cs[2]);
		free(vars->s.cs[3]);
		exit(1);
	}
}
