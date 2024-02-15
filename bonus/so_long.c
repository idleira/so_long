/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:28 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 20:21:57 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		exit(ft_printf("\033[0;31merror\ninvalid number of arguments.\n"));
	ft_memset(&vars, 0, sizeof(vars));
	vars.mlx = mlx_init();
	vars.map_name = argv[1];
	map_read(&vars);
	map_validate(&vars);
	count_all(&vars);
	player_locate(&vars);
	path_validate(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.width * IMG_SIZE,
			vars.height * IMG_SIZE, "so_long");
	images_load(&vars);
	images_draw(&vars);
	mlx_hook (vars.win, 17, 0, press_esc, &vars);
	mlx_hook(vars.win, 2, 1L << 0, player_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
