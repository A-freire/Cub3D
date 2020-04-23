/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/21 16:16:51 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y, int res)
{	
	img_data[(x + y * res) * 4] = (char)b;
	img_data[(x + y * res) * 4 + 1] = (char)g;
	img_data[(x + y * res) * 4 + 2] = (char)r;
	img_data[(x + y * res) * 4 + 3] = 0;
}

void    display(int x, double haut, double bas, t_color color, char *img_data, int res)
{
	(void)color;
	while (bas < haut)
	{
		 putPixel(color.r, color.g, color.b, img_data, x, bas, res);
		bas++;
	}
}

t_all	*clear_image(t_all *all)
{
	int x = 0;
	int y = 0;
	while (x < all->res.x)
	{
		while (y < all->res.y)
		{
			putPixel(0, 0, 0, all->mlx.img_data, x, y, all->res.x);
			y++;
		}
		y=0;
		x++;
	}
	return (all);
}