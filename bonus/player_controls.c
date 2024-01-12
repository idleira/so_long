/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:05 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:42 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_move(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		move_up(vars);
		exit_door(vars);
	}
	if (keycode == 2)
	{
		move_right(vars);
		exit_door(vars);
	}
	if (keycode == 1)
	{
		move_down(vars);
		exit_door(vars);
	}
	if (keycode == 0)
	{
		move_left(vars);
		exit_door(vars);
	}
	return (1);
}
