/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:05 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/12 15:30:20 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	chimken_patrol(vars);
	onscreen_move_counter(vars);
	return (1);
}

void	quit(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	free_images(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_double_pointer(vars->map);
	free_map_copy(vars);
	exit(0);
}

int	press_esc(t_vars *vars)
{
	ft_printf("\n\033[0;35mgame over!\033[0m\n");
	quit(vars);
	exit(0);
}

void	check_exit(t_vars *vars)
{
	check_exit_chimken(vars);
	if (vars->map[vars->player_x][vars->player_y] == 'E'
		&& vars->collected == vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
			vars->display_x, vars->display_y);
		ft_printf("\nyou win!\n");
		quit(vars);
	}
	else if (vars->map[vars->player_x][vars->player_y] == 'E'
			&& vars->collected != vars->counts.count_eggs)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit_o,
			vars->display_x, vars->display_y);
		ft_printf("\nyou have to get all the eggs before you go");
	}
}

void	check_exit_chimken(t_vars *vars)
{
	if (vars->map[vars->player_x][vars->player_y] == 'V')
	{
		if (vars->enemy.direction == 0)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.chimken_r, vars->display_x, vars->display_y);
		else if (vars->enemy.direction == 1)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.chimken_l, vars->display_x, vars->display_y);
		ft_printf("\nchickens reclaimed their eggs!\n");
		quit(vars);
	}
}
