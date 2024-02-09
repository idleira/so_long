/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:30 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/02/09 18:15:58 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

/* extract line with '\n' from buffer */
char	*ft_extract_line(char *rest)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* read from fd until '\n' and put contents into rest*/
char	*ft_read_till_nl(int fd, char *rest)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_gnl_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		rest = ft_gnl_strjoin(rest, buff);
	}
	free(buff);
	return (rest);
}

/* read line from a file specified by fd and return it */
char	*gnl(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (rest)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	rest = ft_read_till_nl(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_extract_line(rest);
	rest = ft_new_rest(rest);
	return (line);
}
