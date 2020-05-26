/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:00:15 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/26 17:05:45 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	write_sprites(t_all *all)
{
	int y;
	int d;

	d = 0;
	y = all->spr.drawstarty;
	while (y < all->spr.drawendy)
	{
		d = (y) * 256 - all->res.y * 128 + all->sprheight * 128;

		all->spr.spry = ((d * all->texwidth) / all->sprheight) / 256;
		if ((all->spr.color[64 * all->spr.spry + all->spr.sprx]) != 0
		&& all->spr.transy < all->spr.buff[all->spr.stripe])
		{
			if (all->spr.stripe >= 0 && all->spr.stripe < all->res.x &&
			y >= 0 && y < all->res.y)
				all->mlx.addr[(y * (int)all->res.x + all->spr.stripe)] =
				all->spr.color[64 * all->spr.spry + all->spr.sprx];
		}
		y++;
	}
}

void	ft_draw_spr(t_all *all)
{
	all->spr.drawstarty = -all->sprheight / 2 + all->res.y / 2;
	if (all->spr.drawstarty < 0)
		all->spr.drawstarty = 0;
	all->spr.drawendy = all->sprheight / 2 + all->res.y / 2;
	if (all->spr.drawendy >= all->res.y)
		all->spr.drawendy = all->res.y - 1;
	all->sprwidth = abs((int)(all->res.y / all->spr.transy));
	all->spr.drawstartx = -all->sprwidth / 2 + all->spr.screen;
	if (all->spr.drawstartx < 0)
		all->spr.drawstartx = 0;
	all->spr.drawendx = all->sprwidth / 2 + all->spr.screen;
	if (all->spr.drawendx >= all->res.x)
		all->spr.drawendx = all->res.x - 1;
}

void	ft_spr_init(t_all *all, int x)
{
	all->spr.x = (all->spr.s[x].x - all->start.pos.y);
	all->spr.y = (all->spr.s[x].y - all->start.pos.x);
	all->spr.invdet = 1.0 / (all->start.fov.y * all->start.dir.x -
	all->start.dir.y * all->start.fov.x);
	all->spr.transx = (all->spr.invdet * (all->start.dir.x * all->spr.x
	- all->start.dir.y * all->spr.y));
	all->spr.transy = (all->spr.invdet * (-all->start.fov.x * all->spr.x
	+ all->start.fov.y * all->spr.y));
	all->spr.screen = (int)((all->res.x / 2) *
	(1 + all->spr.transx / all->spr.transy));
	all->sprheight = abs((int)(all->res.y / all->spr.transy));
}

void	sorting(t_all *all)
{
	int i;

	i = 0;
	while (i < all->tex.spritenb)
	{
		all->spr.s[i].x = all->tex.spritex[i];
		all->spr.s[i].y = all->tex.spritey[i];
		all->spr.s[i].ordre = i;
		all->spr.s[all->spr.s[i].ordre].dist = power_of(all->start.pos, all->spr.s[i].x, all->spr.s[i].y);
		i++;
	}
}

void	sorting_2(t_all *all)
{
	int i;
	int tmp;

	i = 0;
	while (i + 1 < all->tex.spritenb)
	{
		if (all->spr.s[all->spr.s[i].ordre].dist < all->spr.s[all->spr.s[i + 1].ordre].dist)
		{
			tmp = all->spr.s[i].ordre;
			all->spr.s[i].ordre = all->spr.s[i + 1].ordre;
			all->spr.s[i + 1].ordre = tmp;
			sorting_2(all);
		}
		i++;
	}
}

void	ft_sprites(t_all *all)
{
	int x;

	x = 0;
	sorting(all);
	sorting_2(all);
	while(x < all->tex.spritenb)
	{
		ft_spr_init(all, x);
		ft_draw_spr(all);
		all->spr.stripe = all->spr.drawstartx;
		while (all->spr.stripe < all->spr.drawendx)
		{
			all->spr.sprx = (int)(256 * (all->spr.stripe -
			(-all->sprwidth / 2 + all->spr.screen)) * all->texwidth /
			all->sprwidth) / 256;
			if (all->spr.transy > 0 && all->spr.stripe > 0 &&
			all->spr.stripe < all->res.x && all->spr.sprx < 64)
				write_sprites(all);
			all->spr.stripe++;
		}
		x++;
		// printf("x=%i\n",x);
	}
	// printf("yolo\n");
}