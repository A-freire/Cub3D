/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/22 14:43:09 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"
	
int deal_key(int key, void *param)
{
	t_all *all;
	all = param;
	//printf("%d\n", key);
	
	if (key == 53)
		exit(0);
	if (key == 12 || key == 123)
	{
		mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
		//both camera direction and camera plane must be rotated
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(all->rotSpeed) - all->start.dir.y * sin(all->rotSpeed);
		all->start.dir.y = oldDirX * sin(all->rotSpeed) + all->start.dir.y * cos(all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(all->rotSpeed) - all->start.fov.y * sin(all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(all->rotSpeed) + all->start.fov.y * cos(all->rotSpeed);
	}
	if (key == 1)
	{
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.x -= all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.y -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 14 || key == 124)
	{
		mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(-all->rotSpeed) - all->start.dir.y * sin(-all->rotSpeed);
		all->start.dir.y = oldDirX * sin(-all->rotSpeed) + all->start.dir.y * cos(-all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(-all->rotSpeed) - all->start.fov.y * sin(-all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(-all->rotSpeed) + all->start.fov.y * cos(-all->rotSpeed);
	}
	if (key == 13)
	{
		 if(all->map.map[(int)(all->start.pos.x + all->start.dir.x * all->moveSpeed)][(int)all->start.pos.y] == 0) 
			 	all->start.pos.x += all->start.dir.x * all->moveSpeed;
		 if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] == 0) 
			 	all->start.pos.y += all->start.dir.y * all->moveSpeed;
	}
	if (key == 0)
	{
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.y += all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.x -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 2)
	{
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.y -= all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.x += all->start.dir.y * all->moveSpeed;
	}
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