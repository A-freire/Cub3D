/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 11:17:09 by robriard         ###   ########.fr       */
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
void    display(int x, double haut, double bas, t_color color, char *img_data, int res);
void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y, int res);
t_all	*clear_image(t_all *all);

//move
int deal_key(int key, void *param);



int game_on(void* param);
#endif