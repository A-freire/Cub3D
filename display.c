/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/20 11:28:26 by robriard         ###   ########.fr       */
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

void    display(int x, double yMax, double y, t_color color, char *img_data, int res)
{
	while (y < yMax)
	{
		putPixel(color.r, color.g, color.b, img_data, x, y, res);
		y++;
	}
}

t_all	*clear_image(t_all *all)
{
	int x;
	int y;

	x = -1;
	while (++x < all->res.x)
	{
		y = -1;
		while (++y < all->res.y)
			putPixel(0, 0, 0, all->mlx.img_data, x, y, all->res.x);
	}
	return (all);
}