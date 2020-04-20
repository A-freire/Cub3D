/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/20 11:02:34 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

int deal_key(int key, void *param)
{
	t_all *all;
	all = param;
	if (key == 53)
		exit(0);
	if (key == 12 || key == 123)
	{
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(all->rotSpeed) - all->start.dir.y * sin(all->rotSpeed);
		all->start.dir.y = oldDirX * sin(all->rotSpeed) + all->start.dir.y * cos(all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(all->rotSpeed) - all->start.fov.y * sin(all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(all->rotSpeed) + all->start.fov.y * cos(all->rotSpeed);
	}
	if (key == 14 || key == 124)
	{
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(-all->rotSpeed) - all->start.dir.y * sin(-all->rotSpeed);
		all->start.dir.y = oldDirX * sin(-all->rotSpeed) + all->start.dir.y * cos(-all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(-all->rotSpeed) - all->start.fov.y * sin(-all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(-all->rotSpeed) + all->start.fov.y * cos(-all->rotSpeed);
	}
	if (key == 1)
	{
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.x -= all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.y -= all->start.dir.y * all->moveSpeed;
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
		if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1) 
			all->start.pos.y += all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] != 1)
			all->start.pos.x -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 2)
	{
		if(all->map.map[(int)(all->start.pos.x + all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)
		{
			all->start.pos.y -= all->start.dir.x * all->moveSpeed;
		}
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] != 1)
		{
			all->start.pos.x += all->start.dir.y * all->moveSpeed;
		}
	}
	return (key);
}
