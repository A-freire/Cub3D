/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/03/12 15:46:36 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

<<<<<<< HEAD
=======
// static int worldMap[24][24]=
// 	{
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// 	};

static int worldMap[24][24]=
	{
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
	};
>>>>>>> f5335835a8f02767c37b99212640242dd4724123

t_texture		ft_putt(char *texture_addr, t_all *all)
{
	t_texture texture;

	if (!(texture.ptr = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		texture_addr, &texture.w, &texture.h)))
	{
		printf("Error\nThe texture path isn't correct");
		exit(0);
	}
	if (!(texture.data = (int *)mlx_get_data_addr(texture.ptr,
		&texture.bpp, &texture.line_size, &texture.endian)))
	{
		printf("Error\nmlx_get_data_addr texture");
		exit(0);
	}
	return (texture);
}

int game_on(void* param)
{
	t_all *all;
	all = param;
	int x = 0;

	// int texWidth = 64;
	// int texHeight = 64;
	// int texture[8][2147483647];
	
/*	for(int x = 0; x < texWidth; x++)
	for(int y = 0; y < texHeight; y++)
	{
		int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
		//int xcolor = x * 256 / texWidth;
		int ycolor = y * 256 / texHeight;
		int xycolor = y * 128 / texHeight + x * 128 / texWidth;
		texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
		texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
		texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
		texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
		texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
		texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
		texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
		texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
	}
*/

	all->tn = ft_putt("./texture/eagle.xpm", all);
	while(x < all->res.x)
	{
		all->cam.pos.x = 2 * x / all->res.x - 1; //x-coordinate in camera space // camerax
		all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;//raydirx
		all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;//raydiry
		all->map.x = (int)all->start.pos.x;//mapx
		all->map.y = (int)all->start.pos.y;//mapy
		all->deltaDist.x = val_abs(1 / all->cam.dir.x);
		all->deltaDist.y = val_abs(1 / all->cam.dir.y);
		all->hit = 0; //was there a wall hit?
		if(all->cam.dir.x < 0)
		{
			all->step.x = -1;
			all->sideDist.x = (all->start.pos.x - all->map.x) * all->deltaDist.x;
		}
		else
		{
			all->step.x = 1;
			all->sideDist.x = (all->map.x + 1.0 - all->start.pos.x) * all->deltaDist.x;
		}
		if(all->cam.dir.y < 0)
		{
			all->step.y = -1;
			all->sideDist.y = (all->start.pos.y - all->map.y) * all->deltaDist.y;
		}
		else
		{
			all->step.y = 1;
			all->sideDist.y = (all->map.y + 1.0 - all->start.pos.y) * all->deltaDist.y;
		}
		while (all->hit == 0)
		{
			if(all->sideDist.x < all->sideDist.y)
			{
				all->sideDist.x += all->deltaDist.x;
				all->map.x += all->step.x;
				all->side = 0;
			}
			else
			{
				all->sideDist.y += all->deltaDist.y;
				all->map.y += all->step.y;
				all->side = 1;
			}
			if(worldMap[all->map.x][all->map.y] > 0) 
				all->hit = 1;
		}
		if(all->side == 0)
			all->perpWallDist = (all->map.x - all->start.pos.x + (1 - all->step.x) / 2) / all->cam.dir.x;
		else
			all->perpWallDist = (all->map.y - all->start.pos.y + (1 - all->step.y) / 2) / all->cam.dir.y;
		all->lineHeight = (int)(all->res.x / all->perpWallDist);
		all->drawStart = -all->lineHeight / 2 + all->res.x / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineHeight / 2 + all->res.x / 2;
		if(all->drawEnd >= all->res.x)
			all->drawEnd = all->res.x - 1;
		if (worldMap[all->map.x][all->map.y] == 1)
		{
			all->color.r = 255;
			all->color.g = 0;
			all->color.b = 0;
		}
<<<<<<< HEAD
	
=======
	/*	else if (worldMap[all->map.x][all->map.y] == 2)
		{
			all->color.r = 0;
			all->color.g = 255;
			all->color.b = 0;
		}
		else if (worldMap[all->map.x][all->map.y] == 3)
		{
			all->color.r = 0;
			all->color.g = 0;
			all->color.b = 255;
		}
		else if (worldMap[all->map.x][all->map.y] == 4)
		{
			all->color.r = 255;
			all->color.g = 255;
			all->color.b = 255;
		}
		else
		{
			all->color.r = 127;
			all->color.g = 127;
			all->color.b = 127;
		}
	*/	
>>>>>>> f5335835a8f02767c37b99212640242dd4724123
		//  mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,	all->tn.ptr, all->res.x, all->res.y);
		//  mlx_destroy_image(all->mlx.mlx_ptr, all->tn.ptr);
		display(x, all->drawEnd, all->drawStart, all->color, all->mlx.img_data, all->res.x);
		x++;		
	}
	// mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	all = clear_image(all);
	return (0);
}

<<<<<<< HEAD
/*
	void	text_floor(t_all *all)
	{
		for(int y = 0; y < all->res.x; y++)
		{
			// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
			float rayDirX0 = all->start.dir.x - all->start.fov.x;
			float rayDirY0 = all->start.dir.y - all->start.fov.y;
			float rayDirX1 = all->start.dir.x + all->start.fov.x;
			float rayDirY1 = all->start.dir.y + all->start.fov.y;

			// Current y position compared to the center of the screen (the horizon)
			int p = y - all->res.y / 2;

			// Vertical position of the camera.
			float posZ = 0.5 * all->res.y;

			// Horizontal distance from the camera to the floor for the current row.
			// 0.5 is the z position exactly in the middle between floor and ceiling.
			float rowDistance = posZ / p;

			// calculate the real world step vector we have to add for each x (parallel to camera plane)
			// adding step by step avoids multiplications with a weight in the inner loop
			t_vec floorStep;
			floorStep.x = rowDistance * (rayDirX1 - rayDirX0) / all->res.x;
			floorStep.y = rowDistance * (rayDirY1 - rayDirY0) / all->res.x;

			// real world coordinates of the leftmost column. This will be updated as we step to the right.
			t_vec floor;
			floor.x = all->start.pos.x + rowDistance * rayDirX0;
			floor.y = all->start.pos.y + rowDistance * rayDirY0;

			for(int x = 0; x < all->res.x; ++x)
			{
				// the cell coord is simply got from the integer parts of floorX and floorY
				t_vec cell;
				cell.x = (int)(floor.x);
				cell.y = (int)(floor.y);

				// get the texture coordinate from the fractional part
				int tx = (int)(texWidth * (floor.x - cell.x)) & (texWidth - 1);
				int ty = (int)(texHeight * (floor.y - cell.y)) & (texHeight - 1);

				floor.x += floorStep.x;
				floor.y += floorStep.y;

				// choose texture and draw the pixel
				int floorTexture = 3;
				int ceilingTexture = 6;
				Uint32 color;

				// floor
				color = texture[floorTexture][texWidth * ty + tx];
				color = (color >> 1) & 8355711; // make a bit darker
				buffer[y][x] = color;

				//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
				color = texture[ceilingTexture][texWidth * ty + tx];
				color = (color >> 1) & 8355711; // make a bit darker
				buffer[screenHeight - y - 1][x] = color;
			}
		}
	}
*/
t_all ft_mlx(t_all *all)
{
	int osef = 500;
	all->mlx.mlx_ptr = mlx_init();
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->res.x, all->res.y, "YOLO");
	all->mlx.img_ptr = mlx_new_image(all->mlx.mlx_ptr, all->res.x, all->res.y);
	all->mlx.img_data = mlx_get_data_addr(all->mlx.img_ptr, &osef, &osef, &osef);
	return (*all);
}

void	option(t_all *all, t_file *file)
{
	all->start.pos = init_vec(file->spawn.x, file->spawn.y);
	if(file->spawn.facing == 'N')
		all->start.dir = init_vec(0, 1);
	else if(file->spawn.facing == 'S')
		all->start.dir = init_vec(0, -1);
	else if(file->spawn.facing == 'E')
		all->start.dir = init_vec(1, 0);
	else if(file->spawn.facing == 'W')
		all->start.dir = init_vec(-1, 0);
	all->start.fov.x = 0; //planex
	all->start.fov.y = 0.66; //plane y //the 2d raycaster version of camera plane
	all->map = file->map;
	all->res = file->res;
	all->moveSpeed = 0.4;
	all->rotSpeed = 0.5;
	*all = ft_mlx(all);
}

int main(int ac, char **av)
{
	t_all all;
	t_file file;
	(void) ac;
	if (ft_parsing(av[1], &file) < 0)
	{
		printf("ahahahhaahahahahahahahahaah\n");
		return(0);
	}
	option(&all, &file);
	printf("dir x = %f y = %f\n", all.start.dir.x, all.start.dir.y);
=======
int main()
{
	t_all all;
	int osef = 250;

	all.moveSpeed = 0.4;
	all.rotSpeed = 3.141592 / 4.000000;
	all.res.x = 1280;
	all.res.y = 720;
	
	all.mlx.mlx_ptr = mlx_init();
	all.mlx.win_ptr = mlx_new_window(all.mlx.mlx_ptr, all.res.x, all.res.y, "YOLO");
	all.mlx.img_ptr = mlx_new_image(all.mlx.mlx_ptr, all.res.x, all.res.y);
	all.mlx.img_data = mlx_get_data_addr(all.mlx.img_ptr, &osef, &osef, &osef);


	all.start.pos.x = 22;//posx
	all.start.pos.y = 12;//posy  //x and y start position

	all.start.dir.x = -1;//dirx
	all.start.dir.y = 0; //diry //initial direction vector
	all.start.fov.x = 0; //planex
	all.start.fov.y = 0.66; //plane y //the 2d raycaster version of camera plane

>>>>>>> f5335835a8f02767c37b99212640242dd4724123
	all.tf.time = 0; //time of current frame name time
	all.tf.oldtime = 0; //time of previous frame

	// text_floor(&all);
	game_on(&all);
	mlx_do_key_autorepeatoff(all.mlx.mlx_ptr);
	mlx_key_hook(all.mlx.win_ptr, deal_key, &all);
	mlx_loop_hook(all.mlx.mlx_ptr, game_on, &all);
	mlx_loop(all.mlx.mlx_ptr);
	return (0);
}