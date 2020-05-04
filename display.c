/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 14:08:28 by robriard         ###   ########.fr       */
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

void    display(int x, t_all *all)
{
	int start = all->drawStart;
	while (start < all->drawEnd)
	{
		all->texture.y = (int)all->texture.pos & (all->texheight - 1);
		all->texture.pos += all->texture.step;
		all->mlx.img_data [(start * (int)all->res.x + x) * 4] = all->texture.color[(all->texture.y * all->texheight + all->texture.x)];
		all->mlx.img_data [(start * (int)all->res.x + x) * 4 + 1] = all->texture.color[(all->texture.y * all->texheight + all->texture.x)];
		all->mlx.img_data [(start * (int)all->res.x + x) * 4 + 2] = all->texture.color[(all->texture.y * all->texheight + all->texture.x)];
		all->mlx.img_data [(start * (int)all->res.x + x) * 4 + 3] = all->texture.color[(all->texture.y * all->texheight + all->texture.x)];
		start++;
	}
}

void	clear_image(t_all *all)
{
	int x = 0;
	int y = 0;
	while (x < all->res.x)
	{
		while (y < all->res.y)
		{
			if (y < all->res.y / 2)
				putPixel(all->ceiling.r, all->ceiling.g, all->ceiling.b, all->mlx.img_data, x, y, all->res.x);
			else
				putPixel(all->floor.r, all->floor.g, all->floor.b, all->mlx.img_data, x, y, all->res.x);
			y++;
		}
		y = 0;
		x++;
	}
}