/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:07:24 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/05 19:17:54 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(char **map, int count_eggs, int exit_found)
{
	char	**map_copy;
	int 	line_start;
	int 	char_start;
	int 	collect;

	line_start = 0;
	char_start = 0;
	collect = 0;
	map_copy = map_copy(map);
	find_start(map_copy, &line_start, &char_start);
	map_flood(map_copy, line_start, char_start, &collect);
	if (collect != count_eggs)
	{
		ft_printf("some collectables aren't reachable.\n\
				  the game can't be completed.\n");
		return(free_map(map_copy, 1));
	}
	exit_reachable(map_copy, line_start, char_start, &exit_found);
	if (0 == exit_found)
	{
		ft_printf("exit can't be reached.\n\
				  the game can't be completed.\\n\"");
				  return(free_map(map_copy), 1);
	}
	return(free_map(map_copy), 0);
}

char	**copy_map(char **map)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = malloc(sizeof(char) * strlen(map[i]) + 1);
		ft_strlcpy(map_copy[i], map[i], strlen(map[i]) + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_start(char **map_copy, int *line_count, int *char_count)
{
	while (map_copy[*line_count])
	{
		while (map_copy[*line_count][*char_count])
		{
			if (map_copy[*line_count][*char_count] == 'P')
				break ;
			char_count[0]++;
		}
		if (map_copy[*line_count][*char_count] == 'P')
			break ;
		char_count[0] = 0;
		line_count[0]++;
	}
}

int	map_flood(char **map_copy, int line_start, int char_start, int *c)
{
	if ('C' == map_copy[line_start][char_start])
		c[0]++;
	if ('E' != map_copy[line_start][char_start])
		map_copy[line_start][char_start] = 'X';
	if (map_copy[line_start][char_start + 1] == '0'
		|| map_copy[line_start][char_start + 1] == 'C'
		|| map_copy[line_start][char_start + 1] == 'E')
		map_flood(map_copy, line_start, char_start + 1, c);
	if (map_copy[line_start][char_start - 1] == '0'
		|| map_copy[line_start][char_start - 1] == 'C'
		|| map_copy[line_start][char_start - 1] == 'E')
		map_flood(map_copy, line_start, char_start - 1, c);
	if (map_copy[line_start + 1][char_start] == '0'
		|| map_copy[line_start + 1][char_start] == 'C'
		|| map_copy[line_start + 1][char_start] == 'E')
		map_flood(map_copy, line_start + 1, char_start, c);
	if (map_copy[line_start - 1][char_start] == '0' ||
		map_copy[line_start - 1][char_start] == 'C' ||
		map_copy[line_start - 1][char_start] == 'E')
		map_flood(map_copy, line_start - 1, char_start, c);
	return (0);
}

int	exit_reachable(char **map_copy, int line_start, int char_start, int *e)
{
	if ('E' == map_copy[line_start][char_start])
		e[0]++;
	map_copy[line_start][char_start] = 'O';
	if (map_copy[line_start][char_start + 1] == 'X'
		|| map_copy[line_start][char_start + 1] == 'E')
		exit_reachable(map_copy, line_start, char_start + 1, e);
	if (map_copy[line_start][char_start - 1] == 'X'
		|| map_copy[line_start][char_start - 1] == 'E')
		exit_reachable(map_copy, line_start, char_start - 1, e);
	if (map_copy[line_start + 1][char_start] == 'X'
		|| map_copy[line_start + 1][char_start] == 'E')
		exit_reachable(map_copy, line_start + 1, char_start, e);
	if (map_copy[line_start - 1][char_start] == 'X' ||
		map_copy[line_start - 1][char_start] == 'E')
		exit_reachable(map_copy, line_start - 1, char_start, e);
	return (0);
}
