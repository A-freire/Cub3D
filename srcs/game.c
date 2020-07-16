/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:33:10 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:33:11 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_tex(t_all *all)
{
	float	wallx;

	if (all->side == 0)
		wallx = all->start.pos.y + all->perpwalldist * all->cam.dir.y;
	else
		wallx = all->start.pos.x + all->perpwalldist * all->cam.dir.x;
	wallx -= floor(wallx);
	all->tex.x = (int)(wallx * all->texheight);
	if (all->side == 0 && all->cam.dir.x > 0)
		all->tex.x = all->texwidth - all->tex.x - 1;
	if (all->side == 1 && all->cam.dir.y < 0)
		all->tex.x = all->texwidth - all->tex.x - 1;
	all->tex.step = 1.0 * all->texheight / all->lineheight;
	all->tex.pos = (all->drawstart - all->res.y / 2 + all->lineheight / 2)
	* all->tex.step;
	if (all->side == 0 && (all->map.pos.x > all->start.pos.x))
		all->tex.color = (int *)all->tex.tex_s;
	else if (all->side == 1 && (all->map.pos.y < all->start.pos.y))
		all->tex.color = (int *)all->tex.tex_w;
	else if (all->side == 1 && (all->map.pos.y > all->start.pos.y))
		all->tex.color = (int *)all->tex.tex_e;
	else
		all->tex.color = (int *)all->tex.tex_n;
	all->color = (int *)all->spr.tex;
}

void	ft_draw(t_all *all)
{
	if (all->side == 0)
		all->perpwalldist = (all->map.pos.x - all->start.pos.x +
		(1 - all->step.x) / 2) / all->cam.dir.x;
	else
		all->perpwalldist = (all->map.pos.y - all->start.pos.y +
		(1 - all->step.y) / 2) / all->cam.dir.y;
	if (all->perpwalldist == 0)
		all->perpwalldist = 0.1;
	all->lineheight = (int)(all->res.y / all->perpwalldist);
	all->drawstart = -all->lineheight / 2 + all->res.y / 2;
	if (all->drawstart < 0)
		all->drawstart = 0;
	all->drawend = all->lineheight / 2 + all->res.y / 2;
	if (all->drawend >= all->res.y)
		all->drawend = all->res.y - 1;
}

void	ft_hit(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->sidedist.x < all->sidedist.y)
		{
			all->sidedist.x += all->deltadist.x;
			all->map.pos.x += all->step.x;
			all->side = 0;
		}
		else
		{
			all->sidedist.y += all->deltadist.y;
			all->map.pos.y += all->step.y;
			all->side = 1;
		}
		if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 1)
			hit = 1;
	}
}

void	ft_dist(t_all *all)
{
	if (all->cam.dir.x < 0)
	{
		all->step.x = -1;
		all->sidedist.x = (all->start.pos.x - all->map.pos.x)
		* all->deltadist.x;
	}
	else
	{
		all->step.x = 1;
		all->sidedist.x = (all->map.pos.x + 1.0 - all->start.pos.x)
		* all->deltadist.x;
	}
	if (all->cam.dir.y < 0)
	{
		all->step.y = -1;
		all->sidedist.y = (all->start.pos.y - all->map.pos.y)
		* all->deltadist.y;
	}
	else
	{
		all->step.y = 1;
		all->sidedist.y = (all->map.pos.y + 1.0 - all->start.pos.y)
		* all->deltadist.y;
	}
}

void	ft_start(t_all *all, int x)
{
	all->cam.pos.x = 2 * x / all->res.x - 1;
	all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;
	all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;
	all->map.pos.x = (int)all->start.pos.x;
	all->map.pos.y = (int)all->start.pos.y;
	all->deltadist.x = val_abs(1 / all->cam.dir.x);
	all->deltadist.y = val_abs(1 / all->cam.dir.y);
}
