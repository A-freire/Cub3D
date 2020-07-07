/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:01:02 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/07 15:01:03 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		ft_reader(int fd, char **buffer, char **content);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
