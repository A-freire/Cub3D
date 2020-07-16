/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:35:31 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:35:32 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	spr_southd(t_all *all)
{
	int x;

	verread(all);
	x = all->tex.spritenb;
	while (x >= 0)
	{
		ft_spr_init(all, x);
		ft_draw_spr(all);
		all->spr.stripe = all->spr.drawstartx;
		while (all->spr.stripe <= all->spr.drawendx)
		{
			all->spr.sprx = (int)(256 * (all->spr.stripe -
			(-all->sprwidth / 2 + all->spr.screen)) * all->texwidth /
			all->sprwidth) / 256;
			if (all->spr.transy >= 0 && all->spr.stripe >= 0 &&
			all->spr.stripe < all->res.x && all->spr.sprx < 64)
				write_sprites(all);
			all->spr.stripe++;
		}
		x--;
	}
}

void	spr_westd(t_all *all)
{
	int x;

	eurtread(all);
	x = 0;
	while (x <= all->tex.spritenb)
	{
		ft_spr_init(all, x);
		ft_draw_spr(all);
		all->spr.stripe = all->spr.drawstartx;
		while (all->spr.stripe <= all->spr.drawendx)
		{
			all->spr.sprx = (int)(256 * (all->spr.stripe -
			(-all->sprwidth / 2 + all->spr.screen)) * all->texwidth /
			all->sprwidth) / 256;
			if (all->spr.transy >= 0 && all->spr.stripe >= 0 &&
			all->spr.stripe < all->res.x && all->spr.sprx < 64)
				write_sprites(all);
			all->spr.stripe++;
		}
		x++;
	}
}

void	spr_northd(t_all *all)
{
	int x;

	verread(all);
	x = 0;
	while (x <= all->tex.spritenb)
	{
		ft_spr_init(all, x);
		ft_draw_spr(all);
		all->spr.stripe = all->spr.drawstartx;
		while (all->spr.stripe <= all->spr.drawendx)
		{
			all->spr.sprx = (int)(256 * (all->spr.stripe -
			(-all->sprwidth / 2 + all->spr.screen)) * all->texwidth /
			all->sprwidth) / 256;
			if (all->spr.transy >= 0 && all->spr.stripe >= 0 &&
			all->spr.stripe < all->res.x && all->spr.sprx < 64)
				write_sprites(all);
			all->spr.stripe++;
		}
		x++;
	}
}

void	spr_eastd(t_all *all)
{
	int x;

	trueread(all);
	x = all->tex.spritenb;
	while (x >= 0)
	{
		ft_spr_init(all, x);
		ft_draw_spr(all);
		all->spr.stripe = all->spr.drawstartx;
		while (all->spr.stripe <= all->spr.drawendx)
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
