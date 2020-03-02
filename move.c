/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/03/02 15:08:20 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

static int worldMap[24][24]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	
int deal_key(int key, void *param)
{
	t_all *all;
	all = param;

	
	if (key == 53)
		exit(1);
	if (key == 123)
	{
		printf("gauche\n");
		//both camera direction and camera plane must be rotated
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(all->rotSpeed) - all->start.dir.y * sin(all->rotSpeed);
		all->start.dir.y = oldDirX * sin(all->rotSpeed) + all->start.dir.y * cos(all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(all->rotSpeed) - all->start.fov.y * sin(all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(all->rotSpeed) + all->start.fov.y * cos(all->rotSpeed);
	}
	if (key == 125)
	{
		printf("reculer\n");
		if(worldMap[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.x -= all->start.dir.x * all->moveSpeed;
    	if(worldMap[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.y -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 124)
	{
		printf("droite\n");
		//both camera direction and camera plane must be rotated
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(-all->rotSpeed) - all->start.dir.y * sin(-all->rotSpeed);
		all->start.dir.y = oldDirX * sin(-all->rotSpeed) + all->start.dir.y * cos(-all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(-all->rotSpeed) - all->start.fov.y * sin(-all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(-all->rotSpeed) + all->start.fov.y * cos(-all->rotSpeed);
	}
	if (key == 126)
	{
		printf("avancer\n");
		 if(worldMap[(int)(all->start.pos.x + all->start.dir.x * all->moveSpeed)][(int)all->start.pos.y] == 0) 
			 	all->start.pos.x += all->start.dir.x * all->moveSpeed;
		 if(worldMap[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] == 0) 
			 	all->start.pos.y += all->start.dir.y * all->moveSpeed;
	}
return (key);
}