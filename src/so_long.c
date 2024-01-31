/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:28 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/31 19:20:20 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		exit(ft_printf("\033[0;31merror\ninvalid number of arguments\n"));
	vars.mlx = mlx_init();
	vars.map_name = argv[1];
	map_read(&vars);
	validate_map(&vars);
	count_all(&vars);
	player_locate(&vars);
	map_read_2(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.width * IMG_SIZE,
			vars.height * IMG_SIZE, "so_long");
	img_load(&vars);
	img_control(&vars);
	put_wall_floor(&vars, 0, 0);
	mlx_hook (vars.win, 17, 0, press_esc, &vars);
	mlx_hook(vars.win, 2, 1L << 0, player_move, &vars);
	mlx_loop(vars.mlx);
}
