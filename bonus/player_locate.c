/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:46:15 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/11 18:31:53 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_locate(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'P')
			{
				vars->display_x = i;
				vars->display_y = j;
			}
			j++;
		}
		i++;
	}
}

int	onscreen_move_counter(t_vars *vars)
{
	char	*count_string;
	char	*print_string;

	draw_background(vars, vars->height - 1, 0);
	count_string = ft_itoa(vars->move_count);
	print_string = ft_strjoin("moves: ", count_string);
	mlx_string_put(vars->mlx, vars->win, 24,
		vars->height * 128 - 24, 0xFFFFFF, print_string);
	mlx_string_put(vars->mlx, vars->win, 24,
		vars->height * 128 - 12,
		0xFFFFFF, "assets by cup nooble [https://cupnooble.itch.io/]");
	free_pointer(count_string);
	free_pointer(print_string);
	return (0);
}

void	map_print(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			ft_printf("%c", map[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
