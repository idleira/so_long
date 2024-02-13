/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/13 18:31:32 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*path_locate(char **m, char c, int coords[2])
{
	int	i;
	int	j;

	coords[0] = 0;
	coords[1] = 0;
	i = -1;
	while (m[++i] != NULL)
	{
		j = -1;
		while (m[i][++j] != '\0')
		{
			if (m[i][j] == c)
			{
				coords[0] = i;
				coords[1] = j;
				return (coords);
			}
		}
	}
	return (NULL);
}

int path_finder(t_vars *vars)
{
	int coords[2];
	char **m;

	m = vars->path.map_copy;
	if (!path_locate(m, 'P', coords))
		return (1);
	if ((!path_locate(m, 'E', coords) && !path_locate(m, 'C', coords))
		|| !path_locate(m, 'P', coords))
	{
		return (1);
	}
	while (path_locate(m, 'P', coords))
		m = path_create(m);
	if (path_locate(m, 'E', coords) || path_locate(m, 'C', coords))
		return (1);
	return (0);
}

char **path_create(char **m)
{
	int i;
	int j;
	int coords[2];

	i = path_locate(m, 'P', coords)[0];
	j = path_locate(m, 'P', coords)[1];
	if (m[i][j + 1] != '1' && m[i][j + 1] != 'X'
		&& m[i][j + 1] != 'P' && m[i][j + 1] != 'V')
		m[i][j + 1] = 'P';
	if (m[i][j - 1] != '1' && m[i][j - 1] != 'X'
		&& m[i][j - 1] != 'P' && m[i][j - 1] != 'V')
		m[i][j - 1] = 'P';
	if (m[i + 1][j] != '1' && m[i + 1][j] != 'X'
		&& m[i + 1][j] != 'P' && m[i + 1][j] != 'V')
		m[i + 1][j] = 'P';
	if (m[i - 1][j] != '1' && m[i - 1][j] != 'X'
		&& m[i - 1][j] != 'P' && m[i + 1][j] != 'V')
		m[i - 1][j] = 'P';
	m[i][j] = 'X';
	return (m);
}
