/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:57:42 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:42 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	upload_sprites(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->len_height * IMG_SIZE;
	vars->s.cs[0] = mlx_xpm_file_to_image(vars->mlx, "./images/c0.xpm", &x, &y);
	vars->s.cs[1] = mlx_xpm_file_to_image(vars->mlx, "./images/c1.xpm", &x, &y);
	vars->s.cs[2] = mlx_xpm_file_to_image(vars->mlx, "./images/c2.xpm", &x, &y);
	vars->s.cs[3] = mlx_xpm_file_to_image(vars->mlx, "./images/c3.xpm", &x, &y);
}

void	sprite_a(t_vars *vars)
{
	static int	i;
	static int	j;

	if (i <= 6000)
	{
		i++;
		put_egg(vars, 0, 0, j);
		if (i % 4 == 0)
		{
			j++;
			if (j >= 7)
				j = 0;
		}
	}
	else
		i = 0;
}

int	move_counter(t_vars *vars)
{
	vars->mover = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.w, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, vars->mover);
	return (0);
}
