/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:59:39 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 14:26:57 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include "./Get-Next-Line/get_next_line.h"
# include "../header/cub3d_lib.h"

void		ft_clear_copy(int ***copy);
void		ft_error(int error);
void		ft_init_parsing(t_all *a);
int			ft_lifegame(int	**copy);
char		*ft_way(char *line);
int			ft_checkparsing(t_all *a);
int			ft_ismap(char *line);
int			ft_mapheigth(char *file);
int			**ft_initcopy(int **map, int ***copy);
int			**ft_initcheck(int **copy);
int			**ft_squaremap(int **map);
int			ft_strcmp(char *s1, char *s2, int max);
int			ft_parsing(char *file, t_all *a);
int			ft_checktexture(char *texture);
t_all		*ft_map(t_all *ret, char *line, int x);
t_all		*ft_spritecoord(t_all *all);
int			**ft_finalmap(int **map);
t_all		ft_fillstruct(int i, char *line, t_all *a);
t_color		ft_color(char *line);
t_res		ft_res(char *line);
int			ft_checktp(t_all *all);

#endif
