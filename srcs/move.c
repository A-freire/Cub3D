/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/01 15:06:23 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_turn(t_all *all, int i)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = all->start.dir.x;
	all->start.dir.x = all->start.dir.x * cos(all->rotSpeed * i)
	- all->start.dir.y * sin(all->rotSpeed * i);
	all->start.dir.y = oldDirX * sin(all->rotSpeed * i) +
	all->start.dir.y * cos(all->rotSpeed * i);
	oldPlaneX = all->start.fov.x;
	all->start.fov.x = all->start.fov.x * cos(all->rotSpeed * i)
	- all->start.fov.y * sin(all->rotSpeed * i);
	all->start.fov.y = oldPlaneX * sin(all->rotSpeed * i)
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
	if (key == 0)
	{
		if (all->start.dir.x > 0)
			ft_shiftS(all, 1);
		else	
			ft_shiftN(all, 1);	
	}
	if (key == 2)
	{
		if (all->start.dir.x > 0)
			ft_shiftS(all, -1);
		else
			ft_shiftN(all, -1);
	}
}

int 	deal_key(int key, t_all *all)
{	
	if (key == 53)
		exit(0);
	if (key == 1)
		ft_foward(all, -1);
	if (key == 13)
		ft_foward(all, 1);
	if (key == 12 || key == 123)
		ft_turn(all, 1);
	if (key == 14 || key == 124)
		ft_turn(all, -1);
	ft_shift(key, all);
	game_on(all);
	return (key);
}


/*
w = 13
d = 2
s = 1
a = 0
q = 12
e = 14

fleche up = 126
fleche down = 125
fleche right = 124
fleche left = 123
echap = 53
*/