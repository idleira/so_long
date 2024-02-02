/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:27 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/29 17:11:41 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl_join(char *buff, char *read_line)
{
	char	*r;
	int		i;
	int		j;

	if (!buff)
		return (read_line);
	r = gnl_calloc((gnl_strlen(buff, '\0') + \
		gnl_strlen(read_line, '\0') + 1), sizeof(char));
	if (!r)
	{
		free(buff);
		return (NULL);
	}
	i = 0;
	while (buff[i])
	{
		r[i] = buff[i];
		i++;
	}
	j = 0;
	while (read_line[j])
		r[i++] = read_line[j++];
	r[i] = '\0';
	free(buff);
	return (r);
}

char	*gnl_calloc(int nmemb, int size)
{
	char	*r;
	int		i;

	r = malloc(nmemb * size);
	if (!r)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		r[i++] = 0;
	return (r);
}

int	gnl_findnl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlen(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i++])
	{
	}
	return (i);
}
