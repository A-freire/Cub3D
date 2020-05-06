/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/06 11:29:22 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LIB_H
# define CUB3D_LIB_H
# include "includes/minilibx/mlx.h"
# include "cub3d_struct.h"
# include "parsing/ft_parsing.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//maths
t_vec   add_vec(t_vec vec1, t_vec vec2);
t_vec   sub_vec(t_vec vec1, t_vec vec2);
t_vec   init_vec(double x, double y);
t_vec   vec_float(t_vec vec1, double a);
double	val_abs(double t);

//display
void    display(int x, t_all *all);
void    putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y, int res);
void	clear_image(t_all *all);

//move
int deal_key(int key, void *param);

//texture
void	ft_texture(t_all *all);
void     ft_crea_tex(t_all *all);

//main
int game_on(t_all* all);
#endif