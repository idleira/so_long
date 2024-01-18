/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:28 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/18 17:47:45 by ibeliaie         ###   ########.fr       */
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
	counts(&vars);
	upload(&vars);
	map_control(&vars);
	player_locate(&vars);
	map_read_2(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.width * IMG_SIZE,
			vars.len_height * IMG_SIZE, "so_long");
	img_load(&vars);
	control(&vars);
	put_image(&vars, 0, 0);
	mlx_hook (vars.win, 17, 0, press_close_key, &vars);
	mlx_hook(vars.win, 2, 1L << 0, player_move, &vars);
	map_control_dsl(&vars);
	mlx_loop(vars.mlx);
}

int	press_close_key(t_vars *vars)
{
	ft_printf("\n\033[0;35mgame over!\033[0m\n");
	free_exit(vars);
	exit(1);
}

void	error_messages(int i, t_vars *vars)
{
	if (i == 1)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31merror\nwrong map!\n"));
	}
	else if (i == 2)
	{
		exit(ft_printf("\033[0;31merror\nwrong map!(components)\n"));
	}
	else if (i == 3)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31merror\nwrong map!(open map)\n"));
	}
	else if (i == 4)
	{
		free_wrong(vars);
		ft_printf("\033[0;31merror\nwrong map!(collectible count)\n");
		exit(1);
	}
}
