/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/29 19:04:24 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	putpixelr(unsigned char r, int x, int y, t_all all)
{
	all->mlx.img_data[(x + y * (int)all->res.x) * 4 + 2] = (char)r;
}

void	putpixelg(unsigned char g, int x, int y, t_all all)
{
	all->mlx.img_data[(x + y * (int)all->res.x) * 4 + 1] = (char)g;
}

void	putpixelb(unsigned char b, int x, int y, t_all all)
{
	all->mlx.img_data[(x + y * (int)all->res.x) * 4] = (char)b;
}

void	display(int x, t_all *all)
{
	int i;

	i = all->drawStart;
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
	int x;
	int y;

	x = -1;
	while (++x < all->res.x)
	{
		y = -1;
		while (++y < all->res.y)
		{
			if (y < all->res.y / 2)
			{
				putpixelr(all->ceiling.r, x, y, all);
				putpixelg(all->ceiling.g, x, y, all);
				putpixelb(all->ceiling.b, x, y, all);
			}
			else
			{
				putpixelr(all->floor.r, x, y, all);
				putpixelg(all->floor.g, x, y, all);
				putpixelb(all->floor.b, x, y, all);
			}
		}
	}
}
