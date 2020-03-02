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


int oui(void* param)
{
	t_all *all;
	all = param;
	int x = 0;
	
	while(x < all->res.x)
	{
		//calculate ray position and direction
		all->cam.pos.x = 2 * x / all->res.x - 1; //x-coordinate in camera space // camerax
		all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;//raydirx
		all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;//raydiry
		//which box of the map we're in
		all->map.x = (int)all->start.pos.x;//mapx
		all->map.y = (int)all->start.pos.y;//mapy

		//length of ray from current position to next x or y-side
		// t_vec sideDist;//sideDistx et sideDisty

		//length of ray from one x or y-side to next x or y-side
		// t_vec deltaDist;
		all->deltaDist.x = val_abs(1 / all->cam.dir.x);
		all->deltaDist.y = val_abs(1 / all->cam.dir.y);
		// double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		// t_step step;//step.x step.y

		all->hit = 0; //was there a wall hit?
		// int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
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
		//perform DDA
		while (all->hit == 0)
		{
		//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if(worldMap[all->map.x][all->map.y] > 0) 
				all->hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(all->side == 0)
			all->perpWallDist = (all->map.x - all->start.pos.x + (1 - all->step.x) / 2) / all->cam.dir.x;
		else
			all->perpWallDist = (all->map.y - all->start.pos.y + (1 - all->step.y) / 2) / all->cam.dir.y;

		//Calculate height of line to draw on screen
		all->lineHeight = (int)(all->res.x / all->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		all->drawStart = -all->lineHeight / 2 + all->res.x / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineHeight / 2 + all->res.x / 2;
		if(all->drawEnd >= all->res.x)
			all->drawEnd = all->res.x - 1;

		//choose wall color
		if (worldMap[all->map.x][all->map.y] == 1)
		{
			all->color.r = 255;
			all->color.g = 0;
			all->color.b = 0;
		}
		else if (worldMap[all->map.x][all->map.y] == 2)
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

		display(x, all->drawEnd, all->drawStart, all->color, all->mlx.img_data, all->res.x);
		x++;
		// mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
		
	}
		 mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);

	return (0);
}






int main()
{
	t_all all;
	int osef = 250;

	// int x = 0;

	all.moveSpeed = 1;
	all.rotSpeed = 1;
	all.res.x = 800;
	all.res.y = 800;
	
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

	all.tf.time = 0; //time of current frame name time
	all.tf.oldtime = 0; //time of previous frame

	oui(&all);

		// while(x < all.res.x)
		// {
		// 	//calculate ray position and direction
		// 	all.cam.pos.x = 2 * x / all.res.x - 1; //x-coordinate in camera space // camerax
		// 	all.cam.dir.x = all.start.dir.x + all.start.fov.x * all.cam.pos.x;//raydirx
		// 	all.cam.dir.y = all.start.dir.y + all.start.fov.y * all.cam.pos.x;//raydiry
		// 	//which box of the map we're in
		// 	all.map.x = (int)all.start.pos.x;//mapx
		// 	all.map.y = (int)all.start.pos.y;//mapy

		// 	//length of ray from current position to next x or y-side
		// 	// t_vec sideDist;//sideDistx et sideDisty

		// 	//length of ray from one x or y-side to next x or y-side
		// 	// t_vec deltaDist;
		// 	all.deltaDist.x = val_abs(1 / all.cam.dir.x);
		// 	all.deltaDist.y = val_abs(1 / all.cam.dir.y);
		// 	// double perpWallDist;

		// 	//what direction to step in x or y-direction (either +1 or -1)
		// 	// t_step step;//step.x step.y

		// 	all.hit = 0; //was there a wall hit?
		// 	// int side; //was a NS or a EW wall hit?
		// 	//calculate step and initial sideDist
		// 	if(all.cam.dir.x < 0)
		// 	{
		// 		all.step.x = -1;
		// 		all.sideDist.x = (all.start.pos.x - all.map.x) * all.deltaDist.x;
		// 	}
		// 	else
		// 	{
		// 		all.step.x = 1;
		// 		all.sideDist.x = (all.map.x + 1.0 - all.start.pos.x) * all.deltaDist.x;
		// 	}
		// 	if(all.cam.dir.y < 0)
		// 	{
		// 		all.step.y = -1;
		// 		all.sideDist.y = (all.start.pos.y - all.map.y) * all.deltaDist.y;
		// 	}
		// 	else
		// 	{
		// 		all.step.y = 1;
		// 		all.sideDist.y = (all.map.y + 1.0 - all.start.pos.y) * all.deltaDist.y;
		// 	}
		// 	//perform DDA
		// 	while (all.hit == 0)
		// 	{
		// 	//jump to next map square, OR in x-direction, OR in y-direction
		// 		if(all.sideDist.x < all.sideDist.y)
		// 		{
		// 			all.sideDist.x += all.deltaDist.x;
		// 			all.map.x += all.step.x;
		// 			all.side = 0;
		// 		}
		// 		else
		// 		{
		// 			all.sideDist.y += all.deltaDist.y;
		// 			all.map.y += all.step.y;
		// 			all.side = 1;
		// 		}
		// 		//Check if ray has hit a wall
		// 		if(worldMap[all.map.x][all.map.y] > 0) 
		// 			all.hit = 1;
		// 	}
		// 	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		// 	if(all.side == 0)
		// 		all.perpWallDist = (all.map.x - all.start.pos.x + (1 - all.step.x) / 2) / all.cam.dir.x;
		// 	else
		// 		all.perpWallDist = (all.map.y - all.start.pos.y + (1 - all.step.y) / 2) / all.cam.dir.y;

		// 	//Calculate height of line to draw on screen
		// 	all.lineHeight = (int)(all.res.x / all.perpWallDist);

		// 	//calculate lowest and highest pixel to fill in current stripe
		// 	all.drawStart = -all.lineHeight / 2 + all.res.x / 2;
		// 	if(all.drawStart < 0)
		// 		all.drawStart = 0;
		// 	all.drawEnd = all.lineHeight / 2 + all.res.x / 2;
		// 	if(all.drawEnd >= all.res.x)
		// 		all.drawEnd = all.res.x - 1;

		// 	//choose wall color
		// 	if (worldMap[all.map.x][all.map.y] == 1)
		// 	{
		// 		all.color.r = 255;
		// 		all.color.g = 0;
		// 		all.color.b = 0;
		// 	}
		// 	else if (worldMap[all.map.x][all.map.y] == 2)
		// 	{
		// 		all.color.r = 0;
		// 		all.color.g = 255;
		// 		all.color.b = 0;
		// 	}
		// 	else if (worldMap[all.map.x][all.map.y] == 3)
		// 	{
		// 		all.color.r = 0;
		// 		all.color.g = 0;
		// 		all.color.b = 255;
		// 	}
		// 	else if (worldMap[all.map.x][all.map.y] == 4)
		// 	{
		// 		all.color.r = 255;
		// 		all.color.g = 255;
		// 		all.color.b = 255;
		// 	}
		// 	else
		// 	{
		// 		all.color.r = 127;
		// 		all.color.g = 127;
		// 		all.color.b = 127;
		// 	}

		// 	display(x, all.drawEnd, all.drawStart, all.color, all.mlx.img_data, all.res.x);
		// 	x++;
		// }

		mlx_key_hook(all.mlx.win_ptr, deal_key, &all);
		mlx_loop_hook(all.mlx.mlx_ptr, oui, &all);
		// if (move.key != 1)
			// printf("key = %d\n", all.mlx.key);
		// mlx_loop_hook(all.mlx.mlx_ptr, oui, &all);
		
		mlx_put_image_to_window(all.mlx.mlx_ptr, all.mlx.win_ptr, all.mlx.img_ptr, 0, 0);
		mlx_loop(all.mlx.mlx_ptr);
	// }

}

