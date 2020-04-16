/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:59:39 by robriard          #+#    #+#             */
/*   Updated: 2020/03/18 09:34:37 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARCING_H
# define FT_PARCING_H

# include <stdlib.h>
# include <unistd.h>
# include "./Get-Next-Line/get_next_line.h"
# include "parsing_struct.h"

int	        ft_parsing(char *file, t_file *s);
int         *ft_map(char *line);
int		    **ft_finalmap(int **map);
t_file      ft_readparsing(char *file, char *line, t_file *s);
t_res       ft_res(char *line);
t_color     ft_color(char *line);
char		*ft_way(char *line);

int		    ft_strncmp(char *s1, char *s2, int x);
int		    ft_ismap(char *line);
int		    ft_countmap(char *file);
void		ft_error(int error);

int		    ft_checkparsing(t_file *s);
int		    ft_checkmap(int **map, t_spawn spawn);

#endif