/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by robriard          #+#    #+#             */
/*   Updated: 2020/07/13 14:41:55 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"
#include <math.h>

void	ft_turn(t_all *all, int i)
{
	double odx;
	double opx;

	odx = all->start.dir.x;
	all->start.dir.x = all->start.dir.x * cos(all->rotspeed * i)
		- all->start.dir.y * sin(all->rotspeed * i);
	all->start.dir.y = odx * sin(all->rotspeed * i) +
		all->start.dir.y * cos(all->rotspeed * i);
	opx = all->start.fov.x;
	all->start.fov.x = all->start.fov.x * cos(all->rotspeed * i)
		- all->start.fov.y * sin(all->rotspeed * i);
	all->start.fov.y = opx * sin(all->rotspeed * i)
		+ all->start.fov.y * cos(all->rotspeed * i);
}

void	ft_foward(t_all *all, int i)
{
	float posx;
	float posy;
	float dirx;
	float diry;

	posx = all->start.pos.x;
	posy = all->start.pos.y;
	dirx = all->start.dir.x;
	diry = all->start.dir.y;
	if (all->map.map[(int)(posx + (dirx * ((all->movespeed + 0.2) * i)))]
			[(int)posy] != 1)
		all->start.pos.x += dirx * all->movespeed * i;
	if (all->map.map[(int)(posx)]
			[(int)(posy + (diry * ((all->movespeed + 0.2) * i)))] != 1)
		all->start.pos.y += diry * all->movespeed * i;
}

void	ft_shift(int key, t_all *all)
{
	if (key == 97)
	{
		if (all->start.dir.x > 0)
			ft_shifts(all, 1);
		else
			ft_shiftn(all, 1);
	}
	if (key == 100)
	{
		if (all->start.dir.x > 0)
			ft_shifts(all, -1);
		else
			ft_shiftn(all, -1);
	}
}

int		deal_key(int key, t_all *all)
{
	if (key == 65307)
		exit(0);
	if (key == 115)
		ft_foward(all, -1);
	if (key == 119)
		ft_foward(all, 1);
	if (key == 113 || key == 65361)
		ft_turn(all, 1);
	if (key == 101 || key == 65363)
		ft_turn(all, -1);
	ft_shift(key, all);
	if (key == 107)
		ft_reset(all);
	game_on(all);
	return (key);
}
