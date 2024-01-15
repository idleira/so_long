/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:05 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/15 18:18:29 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_move(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
	{
		move_up(vars);
		exit_door(vars);
	}
	if (keycode == D)
	{
		move_right(vars);
		exit_door(vars);
	}
	if (keycode == S)
	{
		move_down(vars);
		exit_door(vars);
	}
	if (keycode == A)
	{
		move_left(vars);
		exit_door(vars);
	}
	return (1);
}
