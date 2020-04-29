/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:59:39 by robriard          #+#    #+#             */
/*   Updated: 2020/04/29 12:02:43 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include <stdlib.h>
# include <unistd.h>
# include "./Get-Next-Line/get_next_line.h"
# include "../cub3d_lib.h"

void	    ft_clear_copy(int ***copy);
void		ft_error(int error);
int 	    ft_lifegame(int	**copy);
char		*ft_way(char *line);
int			ft_checkparsing(t_all a);
int			**ft_initcopy(int **map, int ***copy);
int			**ft_initcheck(int **copy);
int	    	**ft_squaremap(int **map);
int			ft_strcmp(char *s1, char *s2);
int			ft_parsing(char *file, t_all *a);
int			*ft_map(char *line);
int			**ft_finalmap(int **map);
t_all		ft_fillstruct(int i, char *line,t_all *a);
t_color		ft_color(char *line);
t_vec		ft_res(char *line);

#endif