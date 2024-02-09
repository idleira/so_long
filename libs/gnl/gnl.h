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

char	*ft_new_rest(char *rest);
size_t	ft_gnl_strlen(const char *str);
char	*ft_extract_line(char *rest);
char	*ft_gnl_strchr(char *str, int find);
char	*ft_read_till_nl(int fd, char *rest);
char	*ft_gnl_strjoin(char *rest, char *buff);

#endif