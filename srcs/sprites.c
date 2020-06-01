/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:00:15 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/28 14:44:12 by robriard         ###   ########.fr       */
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

void	trueread(t_all *all)
{
    int        x;
    int        y;
    int        index;

    index = 0;
    y = -1;
    while (all->map.map[0][++y] != -42)
    {
        x = -1;
        while (all->map.map[++x][0] != -42)
        {
            if (all->map.map[x][y] == 2)
            {
                all->tex.spritey[index] = x + 0.5;
                all->tex.spritex[index] = y + 0.5;
                index++;
            }
        }
    }
}

void	ft_sprites(t_all *all)
{
	int x;
	if (all->start.dir.x > 0.7)
	{
		all = ft_spritecoord(all);
		x = all->tex.spritenb;
		while(x >= 0)
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
			x--;
		}
	}else if (all->start.dir.x < 0.7 && all->start.dir.x > -0.7 && all->start.dir.y < -0.7)
	{
		trueread(all);
		x = 0;
		while(x <= all->tex.spritenb)
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
		}
	}else if (all->start.dir.x < -0.7)
	{
		all = ft_spritecoord(all);
		x = 0;
		while(x <= all->tex.spritenb)
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
		}
	}else
	{
		trueread(all);
		x = all->tex.spritenb;
		while(x >= 0)
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
			x--;
		}
	}
}