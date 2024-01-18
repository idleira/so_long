/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:15 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/12 16:37:29 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read_2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->path.imap = (int **)malloc(sizeof(int *) * (vars->len_height + 1));
	while (i < vars->len_height)
	{
		vars->path.imap[i] = malloc(sizeof(int) * (vars->width + 1));
		j = 0;
		while (j < vars->width)
		{
			if (i == vars->i && j == vars->j)
				vars->path.imap[i][j] = 1;
			else
				vars->path.imap[i][j] = 0;
			j++;
		}
		vars->path.imap[i][j] = '\0';
		i++;
	}
	vars->path.imap[i] = NULL;
}
