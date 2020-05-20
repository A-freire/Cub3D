/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/20 18:58:16 by afreire-         ###   ########.fr       */
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

//main
void	game_on(t_all* all);
int		ft_finish(void *param);
char	*ft_windowname(char *file);
void	ft_init(t_all *all, char *windowname);

//game
void	ft_start(t_all *all, int x);
void	ft_dist(t_all *all);
void	ft_hit(t_all *all);
void	ft_draw(t_all *all);
void	ft_tex(t_all *all);

//texture
void	ft_crea_tex(t_all *all);
void	ft_texture(t_all *all);

//sprites
void	write_sprites(t_all *all);
void	ft_draw_spr(t_all *all);
void	ft_spr_init(t_all *all, int x);
void	sorting(t_all *all);
void	ft_sprites(t_all *all);

//display
void	putPixelr(unsigned char r, char *img_data, int x, int y, int res);
void	putPixelg(unsigned char g, char *img_data, int x, int y, int res);
void	putPixelb(unsigned char b, char *img_data, int x, int y, int res);
void	display(int x, t_all *all);
void	clear_image(t_all *all);

//move
void	ft_foward(t_all *all, int i);
void	ft_turn(t_all *all, int i);
void	ft_shift(int key, t_all *all);
int		deal_key(int key, t_all *all);

//shift
void	ft_shiftS(t_all *all, int i);
void	ft_shiftN(t_all *all, int i);

//tools
t_vec	init_vec(double x, double y);
double	val_abs(double t);
int		power_of(t_vec pos, float spr_x, float spr_y);
void	ft_switch(t_all *all, int x, int y);

#endif