/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:35:11 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:35:12 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	write_sprites(t_all *all)
{
	int y;
	int d;

	d = 0;
	y = all->spr.drawstarty;
	while (y <= all->spr.drawendy)
	{
		d = (y) * 256 - all->res.y * 128 + all->sprheight * 128;
		all->spr.spry = ((d * all->texwidth) / all->sprheight) / 256;
		if ((all->color[64 * all->spr.spry + all->spr.sprx]) != 0
		&& all->spr.transy < all->spr.buff[all->spr.stripe])
		{
			if (all->spr.stripe >= 0 && all->spr.stripe < all->res.x &&
			y >= 0 && y < all->res.y)
				all->mlx.addr[(y * (int)all->res.x + all->spr.stripe)] =
				all->color[64 * all->spr.spry + all->spr.sprx];
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
	if ((all->tp.coord[0][0] == all->tex.spritex[x] && all->tp.coord[1][0]
	== all->tex.spritey[x])
	|| (all->tp.coord[0][1] == all->tex.spritex[x] && all->tp.coord[1][1]
	== all->tex.spritey[x]))
		all->color = (int *)all->tp.tex;
	else
		all->color = (int *)all->spr.tex;
	all->spr.x = (all->tex.spritex[x] - all->start.pos.y);
	all->spr.y = (all->tex.spritey[x] - all->start.pos.x);
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

void	ft_sprites(t_all *all)
{
	if (all->start.dir.x < -0.7)
		if (all->start.dir.y <= 0)
			spr_northg(all);
		else
			spr_northd(all);
	else if (all->start.dir.y > 0.7)
		if (all->start.dir.x < 0)
			spr_eastg(all);
		else
			spr_eastd(all);
	else if (all->start.dir.x > 0.7)
		if (all->start.dir.y < 0)
			spr_southd(all);
		else
			spr_southg(all);
	else
	{
		if (all->start.dir.x >= 0)
			spr_westd(all);
		else
			spr_westg(all);
	}
}
