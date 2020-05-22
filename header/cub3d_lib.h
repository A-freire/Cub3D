/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/22 15:15:19 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LIB_H
# define CUB3D_LIB_H
# include "../includes/minilibx/mlx.h"
# include "cub3d_struct.h"
# include "../parsing/ft_parsing.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int		deal_key(int key, t_all *all);
int		power_of(t_vec pos, float spr_x, float spr_y);
int		ft_finish(void *param);
char	*ft_windowname(char *file);
void	game_on(t_all *all);
void	ft_init(t_all *all, char *windowname);
void	ft_start(t_all *all, int x);
void	ft_dist(t_all *all);
void	ft_hit(t_all *all);
void	ft_draw(t_all *all);
void	ft_tex(t_all *all);
void	ft_crea_tex(t_all *all);
void	ft_texture(t_all *all);
void	write_sprites(t_all *all);
void	ft_draw_spr(t_all *all);
void	ft_spr_init(t_all *all, int x);
void	sorting(t_all *all);
void	ft_sprites(t_all *all);
void	putPixelr(unsigned char r, char *img_data, int x, int y, int res);
void	putPixelg(unsigned char g, char *img_data, int x, int y, int res);
void	putPixelb(unsigned char b, char *img_data, int x, int y, int res);
void	display(int x, t_all *all);
void	clear_image(t_all *all);
void	ft_foward(t_all *all, int i);
void	ft_turn(t_all *all, int i);
void	ft_shift(int key, t_all *all);
void	ft_shiftS(t_all *all, int i);
void	ft_shiftN(t_all *all, int i);
void	*ft_memset(void *b, int c, size_t n);
void	ft_switch(t_all *all, int x, int y);
void    ft_bmp(t_all *all);
t_vec	init_vec(double x, double y);
double	val_abs(double t);

#endif
