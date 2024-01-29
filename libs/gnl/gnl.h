/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:32 by ibeliaie          #+#    #+#             */
/*   Updated: 2024/01/29 17:13:20 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*gnl(int fd);
char	*gnl_read(int fd, char *line);
char	*gnl_retline(char *line);
char	*gnl_save(char *buff);

int		gnl_strlen(char *s, char c);
int		gnl_findnl(char *s);
char	*gnl_calloc(int nmemb, int size);
char	*gnl_join(char *buff, char *read_line);

#endif