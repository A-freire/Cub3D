/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:32:15 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/29 18:33:03 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	spr_south(t_all *all)
{
	int x;

	revread(all);
	x = all->tex.spritenb;
	while (x >= 0)
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

void	spr_west(t_all *all)
{
	int x;

	trueread(all);
	x = 0;
	while (x <= all->tex.spritenb)
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
}

void	spr_north(t_all *all)
{
	int x;

	revread(all);
	x = 0;
	while (x <= all->tex.spritenb)
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
}

void	spr_east(t_all *all)
{
	int x;

	trueread(all);
	x = all->tex.spritenb;
	while (x >= 0)
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
