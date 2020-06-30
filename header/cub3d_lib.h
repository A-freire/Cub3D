/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:43:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/30 12:36:16 by robriard         ###   ########.fr       */
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

//cub3d.c
void	game_on(t_all *all);
char	*ft_windowname(char *file);
int	    ft_finish(void *param);
void	ft_init(t_all *all, char *windowname);

//display.c
void	putpixelr(unsigned char r, int x, int y, t_all *all);
void	putpixelg(unsigned char g, int x, int y, t_all *all);
void	putpixelb(unsigned char b, int x, int y, t_all *all);
void	display(int x, t_all *all);
void	clear_image(t_all *all);

//tools.c
t_vec	init_vec(double x, double y);
double	val_abs(double t);
int		power_of(t_vec pos, float spr_x, float spr_y);
void	*ft_memset(void *b, int c, size_t n);
void	ft_save(t_all *all);

//texture.c
void	ft_crea_tex(t_all *all);
void	ft_texture(t_all *all);

//sprites.c
void	write_sprites(t_all *all);
void	ft_draw_spr(t_all *all);
void	ft_spr_init(t_all *all, int x);
void	ft_sprites(t_all *all);

//order.c
void    spr_south(t_all *all);
void	spr_west(t_all *all);
void	spr_north(t_all *all);
void	spr_east(t_all *all);

//read.c
void	trueread(t_all *all);
void	revread(t_all *all);

//shift.c
void	ft_shiftn(t_all *all, int i);
void    ft_othern(t_all *all, int i);
void	ft_shifts(t_all *all, int i);
void    ft_others(t_all *all, int i);

//move.c
void	ft_turn(t_all *all, int i);
void	ft_foward(t_all *all, int i);
void	ft_shift(int key, t_all *all);
int		deal_key(int key, t_all *all);

//game.c
void	ft_tex(t_all *all);
void	ft_draw(t_all *all);
void	ft_hit(t_all *all);
void	ft_dist(t_all *all);
void	ft_start(t_all *all, int x);

//ft_bmp.c
void	set_header(unsigned char *header, int param);
void	imgbmp(t_all *all, t_bmp *bmp);
void	ft_header(t_all *all, t_bmp *bmp);
void    ft_bmp(t_all *all);

//bonus.c
void	colors(t_all *all, int x, int y);
void	heal(t_all *all);
void	ft_reset(t_all *all);
void	sprint(t_all *all);
void	sneack(t_all *all);
void	ft_tp(t_all *all);

//norme.c
void    ft_ncheckpar(t_all a, int **copy);
void    ft_ase(t_all *all);
void	ft_asse(t_all *all);
void	ft_assse(t_all *all);
void	ft_asssse(t_all *all);
void	ft_assssse(t_all *all);

#endif
