/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:05 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/19 18:19:03 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		press_close_key(vars);
	if (keycode == XK_w || keycode == XK_Up)
	{
		move_up(vars);
		exit_door(vars);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		move_right(vars);
		exit_door(vars);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		move_down(vars);
		exit_door(vars);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		move_left(vars);
		exit_door(vars);
	}
	return (1);
}
