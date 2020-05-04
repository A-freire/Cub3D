/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 15:05:48 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

t_all	*ft_turn(t_all *all, int i)
{

	double oldDirX;
	double oldPlaneX;

	oldDirX = all->start.dir.x;
	all->start.dir.x = all->start.dir.x * cos(all->rotSpeed * i) - all->start.dir.y * sin(all->rotSpeed * i);
	all->start.dir.y = oldDirX * sin(all->rotSpeed * i) + all->start.dir.y * cos(all->rotSpeed * i);
	oldPlaneX = all->start.fov.x;
	all->start.fov.x = all->start.fov.x * cos(all->rotSpeed * i) - all->start.fov.y * sin(all->rotSpeed * i);
	all->start.fov.y = oldPlaneX * sin(all->rotSpeed * i) + all->start.fov.y * cos(all->rotSpeed * i);
	return (all);
}

t_all	*ft_shift(t_all *all, int i)
{
	if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * ((all->moveSpeed + 0.1) * i))][(int)(all->start.pos.y )] != 1)
		all->start.pos.y += (all->start.dir.x * all->moveSpeed * i);
	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * ((all->moveSpeed + 0.1) * i))] != 1) 
		all->start.pos.x -= (all->start.dir.y * all->moveSpeed * i);
	return (all);
}

t_all	*ft_foward(t_all *all, int i)
{
	if(all->map.map[(int)(all->start.pos.x + (all->start.dir.x * ((all->moveSpeed + 0.1) * i)))][(int)all->start.pos.y] != 1) 
		all->start.pos.x += all->start.dir.x * all->moveSpeed * i;
	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + (all->start.dir.y * ((all->moveSpeed + 0.1) * i)))] != 1) 
		all->start.pos.y += all->start.dir.y * all->moveSpeed * i;
	return (all);			
}

int 	deal_key(int key, void *param)
{
	t_all *all;
	all = param;
	
	if (key == 53)
		exit(0);
	if (key == 1)
		all = ft_foward(all, -1);
	if (key == 13)
		 all = ft_foward(all, 1);
	if (key == 12 || key == 123)
	{
		mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
		all = ft_turn(all, 1);
	}
	if (key == 14 || key == 124)
	{
		mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
		all = ft_turn(all, -1);
	}
	if (key == 0)
		all = ft_shift(all, 1);	
	if (key == 2)
		all = ft_shift(all, -1);
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