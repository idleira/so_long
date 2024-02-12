/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/12 19:20:27 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*path_char_locate(char **map, char c, int coords[2])
{
	int	i;
	int	j;

	i = 0;
	coords[0] = 0;
	coords[1] = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coords[0] = i;
				coords[1] = j;
			}
			j++;
		}
		i++;
	}
	if (coords[0] == 0 && coords[1] == 0)
		return (NULL);
	return (coords);
}


int	path_finder(char **map)
{
	int	coords[2];
	int	complete;

	complete = 0;
	map_print(map);
	if (!path_char_locate(map, 'P', coords))
		return (1);
	while (!complete)
	{
		if ((!path_char_locate(map, 'E', coords) && !path_char_locate(map, 'C', coords))
			|| !path_char_locate(map, 'P', coords))
		{
			complete = 1;
			break ;
		}
		map = create_path(map);
	}
	if (path_char_locate(map, 'E', coords) || path_char_locate(map, 'C', coords))
		return (1);
	return (0);
}

char	**create_path(char **map)
{
	int	i;
	int	j;
	int	coords[2];

	i = path_char_locate(map, 'P', coords)[0];
	j = path_char_locate(map, 'P', coords)[1];
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'X' && map[i][j + 1] != 'P')
		map[i][j + 1] = 'P';
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'X' && map[i][j - 1] != 'P')
		map[i][j - 1] = 'P';
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'X' && map[i + 1][j] != 'P')
		map[i + 1][j] = 'P';
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'X' && map[i - 1][j] != 'P')
		map[i - 1][j] = 'P';
	map[i][j] = 'X';
	return (map);
}
