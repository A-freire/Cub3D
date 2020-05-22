/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/22 12:53:34 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void putPixelr(unsigned char r, char *img_data, int x, int y, int res)
{	
	img_data[(x + y * res) * 4 + 2] = (char)r;
}

void putPixelg(unsigned char g, char *img_data, int x, int y, int res)
{	
	img_data[(x + y * res) * 4 + 1] = (char)g;
}

void putPixelb(unsigned char b, char *img_data, int x, int y, int res)
{	
	img_data[(x + y * res) * 4] = (char)b;
}

void    display(int x, t_all *all)
{
	int i = all->drawStart;
	while (i < all->drawEnd)
	{
		all->tex.y = (int)all->tex.pos & (all->texheight - 1);
		all->tex.pos += all->tex.step;
		all->mlx.addr[(i * (int)all->res.x + x)] = all->tex.color[(all->tex.y *
		all->texheight + all->tex.x)];
		i++;
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
			{
				putPixelr(all->ceiling.r, all->mlx.img_data, x, y, all->res.x);
				putPixelg(all->ceiling.g, all->mlx.img_data, x, y, all->res.x);
				putPixelb(all->ceiling.b, all->mlx.img_data, x, y, all->res.x);
			}
			else
			{	
				putPixelr(all->floor.r, all->mlx.img_data, x, y, all->res.x);
				putPixelg(all->floor.g, all->mlx.img_data, x, y, all->res.x);
				putPixelb(all->floor.b, all->mlx.img_data, x, y, all->res.x);
			}
			y++;
		}
		y = 0;
		x++;
	}
}