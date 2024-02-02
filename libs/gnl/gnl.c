/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:30 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/02 21:09:16 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl_save(char *buff)
{
	char	*save;
	int		i;
	int		j;

	i = gnl_findnl(buff);
	if (i == -1 || !buff[i])
	{
		free(buff);
		return (NULL);
	}
	save = gnl_calloc(gnl_strlen(buff, '\0') - i + 2, sizeof(char));
	j = 0;
	if (gnl_findnl(buff) >= 0)
	{
		while (buff[i] != '\n')
		{
			i++;
		}
		i++;
	}
	while (buff[i])
		save[j++] = buff[i++];
	free(buff);
	return (save);
}

char	*gnl_retline(char *line)
{
	char	*r;
	int		i;

	if (!*line)
		return (NULL);
	r = gnl_calloc(gnl_strlen(line, '\n') + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		r[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		r[i++] = '\n';
	r[i] = '\0';
	return (r);
}

char	*gnl_read(int fd, char *line)
{
	char	*buff;
	int		bytes_read;

	if (!line)
		line = gnl_calloc(1, sizeof(char));
	buff = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(line);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0 && gnl_findnl(buff) < 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(line);
			buff = NULL;
			return (NULL);
		}
		buff[bytes_read] = '\0';
		line = gnl_join(line, buff);
	}
	free(buff);
	return (line);
}

char	*gnl(int fd)
{
	static char	*buff;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff)
		{
			free(buff);
			buff = NULL;
		}
		return (NULL);
	}
	buff = gnl_read(fd, buff);
	if (!buff)
		return (NULL);
	r = gnl_retline(buff);
	buff = gnl_save(buff);
	return (r);
}
