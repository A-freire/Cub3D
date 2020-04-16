/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:50:07 by afreire-          #+#    #+#             */
/*   Updated: 2020/03/12 16:43:33 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

// void	up_down(t_all *all)
// {
// 	if (all->move.up == 1)
// 	{

// 	}
// 	else if (all->move.down == 1)
// 	{
// 		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
// 			all->start.pos.x -= all->start.dir.x * all->moveSpeed;
//     	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
// 			all->start.pos.y -= all->start.dir.y * all->moveSpeed;
// 	}
// }

int deal_key(int key, void *param)
{
	t_all *all;
	all = param;
	//  printf("%d\n", key);
	// printf("start x = %d | y = %d\n", (int)(all->start.pos.x), (int)(all->start.pos.y));
	if (key == 53)
		exit(0);
	if (key == 12 || key == 123)
	{
		printf("rotation gauche\n");
		//both camera direction and camera plane must be rotated
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(all->rotSpeed) - all->start.dir.y * sin(all->rotSpeed);
		all->start.dir.y = oldDirX * sin(all->rotSpeed) + all->start.dir.y * cos(all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(all->rotSpeed) - all->start.fov.y * sin(all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(all->rotSpeed) + all->start.fov.y * cos(all->rotSpeed);
	}
	if (key == 14 || key == 124)
	{
		printf("rotation droite\n");
		//both camera direction and camera plane must be rotated
		double oldDirX = all->start.dir.x;
		all->start.dir.x = all->start.dir.x * cos(-all->rotSpeed) - all->start.dir.y * sin(-all->rotSpeed);
		all->start.dir.y = oldDirX * sin(-all->rotSpeed) + all->start.dir.y * cos(-all->rotSpeed);
		double oldPlaneX = all->start.fov.x;
		all->start.fov.x = all->start.fov.x * cos(-all->rotSpeed) - all->start.fov.y * sin(-all->rotSpeed);
		all->start.fov.y = oldPlaneX * sin(-all->rotSpeed) + all->start.fov.y * cos(-all->rotSpeed);
	}
	if (key == 1)
	{
		printf("reculer\n");
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] == 0)
			all->start.pos.x -= all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] == 0) 
			all->start.pos.y -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 13)
	{
		printf("avancer\n");
		 if(all->map.map[(int)(all->start.pos.x + all->start.dir.x * all->moveSpeed)][(int)all->start.pos.y] == 0) 
			 	all->start.pos.x += all->start.dir.x * all->moveSpeed;
		 if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] == 0) 
			 	all->start.pos.y += all->start.dir.y * all->moveSpeed;
	}
	if (key == 0)
	{
		printf("gauche\n");
		// printf("x = %d | y = %d\n", (int)(all->start.pos.x), (int)all->start.pos.y));
		if(all->map.map[(int)(all->start.pos.x)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1) 
			all->start.pos.y += all->start.dir.x * all->moveSpeed;
    	if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y)] != 1)
			all->start.pos.x -= all->start.dir.y * all->moveSpeed;
	}
	if (key == 2)
	{
		printf("droite\n");
		if(all->map.map[(int)(all->start.pos.x + all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)
		{
			// printf("x = %d | y = %d\n", (int)(all->start.pos.x + all->start.dir.x * all->moveSpeed), (int)(all->start.pos.y + all->start.dir.y * all->moveSpeed));
			all->start.pos.y -= all->start.dir.x * all->moveSpeed;
		}
		if(all->map.map[(int)(all->start.pos.x - all->start.dir.x * all->moveSpeed)][(int)(all->start.pos.y - all->start.dir.y * all->moveSpeed)] != 1)
		{
			// printf("x = %d\n", (int)(all->start.pos.x - all->start.dir.x * all->moveSpeed));
			// printf("y = %d\n", (int)(all->start.pos.y - all->start.dir.y * all->moveSpeed));
			all->start.pos.x += all->start.dir.y * all->moveSpeed;
		}
	}
	// printf("end x = %d | y = %d\n", (int)(all->start.pos.x), (int)(all->start.pos.y));
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

up = 126
down = 125
gauche = 123
droite = 124
*/