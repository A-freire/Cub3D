/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/25 15:10:45 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LIB_H
# define CUB3D_LIB_H
# include "../includes/minilibx/mlx.h"
# include "cub3d_struct.h"

//maths
t_vec   add_vec(t_vec vec1, t_vec vec2);
t_vec   sub_vec(t_vec vec1, t_vec vec2);
t_vec   init_vec(float x, float y);
t_vec   vec_float(t_vec vec1, float a);
float prod_sca(t_vec vec1, t_vec vec2);
int     sec_degre(float a, float b, float c, float *s);
t_vec   normalize(t_vec vector);
t_vec   sphere_normal(t_vec intersec, t_vec centre);
float eq_car_pl(t_vec vec, t_vec point);
t_vec	prod_vec(t_vec u, t_vec v);
float	val_abs(float t);

//display
void    display(int x, float bas, float haut, t_color color, char *img_data);
void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y);







#endif