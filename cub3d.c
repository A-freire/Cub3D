/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:02:35 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/25 15:10:44 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"


int main()
{
	int worldMap[24][24]=
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
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int osef = 250;
    char *img_data;
    int x = 0;
    

	t_res res;
	res.x = 500;
	res.y = 500;
    
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, res.x, res.y, "YOLO");
	img_ptr = mlx_new_image(mlx_ptr, res.x, res.y);
	img_data = mlx_get_data_addr(img_ptr, &osef, &osef, &osef);

	t_start start;
	start.pos = init_vec(22,12);
	start.dir = init_vec(-1,0);
	start.fov = init_vec(0,0.66);

	t_tf tf;
	tf.current = 0;
	tf.previous = 0;
	
	t_cam cam;
	

		while (x < res.x)
		{
			cam.pos.x = 2 * res.x - 1;
			cam.dir.x = start.dir.x + start.fov.x * cam.pos.x; //raydirx
			cam.dir.y = start.dir.y + start.fov.y * cam.pos.x; //raydiry

			t_map map;
			map.x = start.pos.x;
			map.y = start.pos.y;

			t_vec sidedist;

			t_vec deltadist;
			deltadist.x = val_abs(1 / cam.dir.x);
			deltadist.y = val_abs(1 / cam.dir.y);
			float perpwalldist;

			t_vec step;

			float hit = 0;
			float side;

			if (cam.dir.x < 0)
			{
				step.x = -1;
				sidedist.x = (start.pos.x - map.x) * deltadist.x;
			}
			else
			{
				step.x = 1;
				sidedist.x = (start.pos.x + 1 - map.x) * deltadist.x;
			}
			if (cam.dir.x < 0)
			{
				step.y = -1;
				sidedist.y = (start.pos.y - map.y) * deltadist.y;
			}
			else
			{
				step.y = 1;
				sidedist.y = (start.pos.y + 1 - map.y) * deltadist.y;
			}
			

			while (hit == 0)
			{
				if(sidedist.x < sidedist.y)
				{
					sidedist.x += deltadist.x;
					map.x += step.x;
					side = 0;
				}
				else
				{
					sidedist.y += deltadist.y;
					map.y += step.y;
					side = 1;
				}

				if(worldMap[map.x][map.y] > 0) 
					hit = 1;
			}


			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0)
				perpwalldist = (map.x - start.pos.x + (1 - step.x) / 2) / cam.dir.x;
			else
		        perpwalldist = (map.y - start.pos.y + (1 - step.y) / 2) / cam.dir.y;

			//Calculate height of line to draw on screen
			float lineHeight = (res.y / perpwalldist);

			//calculate lowest and highest pixel to fill in current stripe
			float drawStart = -lineHeight / 2 + res.y / 2;
			if(drawStart < 0)
				drawStart = 0;
			float drawEnd = lineHeight / 2 + res.y / 2;
			if(drawEnd >= res.y)
				drawEnd = res.y - 1;

			//choose wall color
			t_color color;
			if (worldMap[map.x][map.y] == 1)
			{
				color.r = 255;
				color.g = 0;
				color.b = 0;
			}
			else if (worldMap[map.x][map.y] == 2)
			{
				color.r = 0;
				color.g = 255;
				color.b = 0;
			}
			else if (worldMap[map.x][map.y] == 3)
			{
				color.r = 0;
				color.g = 0;
				color.b = 255;
			}
			else if (worldMap[map.x][map.y] == 4)
			{
				color.r = 255;
				color.g = 255;
				color.b = 255;
			}
			else
			{
				color.r = 127;
				color.g = 127;
				color.b = 127;
			}

			//draw the pixels of the stripe as a vertical line
			display(x, drawStart, drawEnd, color, img_data);
			x++;
		}


    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}