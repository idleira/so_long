/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:05 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 19:47:25 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		press_esc(vars);
	if (keycode == XK_w || keycode == XK_Up)
	{
		move_up(vars);
		check_exit(vars);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		move_right(vars);
		check_exit(vars);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		move_down(vars);
		check_exit(vars);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		move_left(vars);
		check_exit(vars);
	}
	return (1);
}

void	check_exit(t_vars *vars)
{
	if (vars->map[vars->display_x][vars->display_y] == 'E'
		&& vars->collected == vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
			vars->player_x, vars->player_y);
		ft_printf("\nyou win!\n");
		exit(0);
	}
	else if (vars->map[vars->display_x][vars->display_y] == 'E'
			&& vars->collected != vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exit,
			vars->player_x, vars->player_y);
		ft_printf("\nyou have to get all the eggs before you go");
	}
}
