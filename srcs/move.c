/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/29 18:39:15 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"
#include <math.h>

void	ft_turn(t_all *all, int i)
{
	double odx;
	double opx;

	odx = all->start.dir.x;
	all->start.dir.x = all->start.dir.x * cos(all->rotSpeed * i)
	- all->start.dir.y * sin(all->rotSpeed * i);
	all->start.dir.y = odx * sin(all->rotSpeed * i) +
	all->start.dir.y * cos(all->rotSpeed * i);
	opx = all->start.fov.x;
	all->start.fov.x = all->start.fov.x * cos(all->rotSpeed * i)
	- all->start.fov.y * sin(all->rotSpeed * i);
	all->start.fov.y = opx * sin(all->rotSpeed * i)
	+ all->start.fov.y * cos(all->rotSpeed * i);
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
	if (all->map.map[(int)(posx + (dirx * ((all->moveSpeed + 0.2) * i)))]
	[(int)posy] != 1)
		all->start.pos.x += dirx * all->moveSpeed * i;
	if (all->map.map[(int)(posx)]
	[(int)(posy + (diry * ((all->moveSpeed + 0.2) * i)))] != 1)
		all->start.pos.y += diry * all->moveSpeed * i;
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
	if (key == 65507)
		sneack(all);
	if (key == 114)
		sprint(all);
	ft_shift(key, all);
	game_on(all);
	return (key);
}
