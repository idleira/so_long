/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:46:15 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 17:28:30 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
